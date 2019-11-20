#repo brief

reference: https://source.android.com/setup/develop/repo

Repo command reference
##Repo usage takes the following form: `Repo用法使用以下格式`
```
repo <COMMAND> <OPTIONS>
```
Optional elements are shown in brackets [ ]. For example, many commands take a project list as an argument. You can specify project-list as a list of names or a list of paths to local source directories for the projects:
`可选项项都显示在中括号[]里. 例如，许多命令以项目列表作为参数。您可以将项目列表指定为项目的本地源目录的名称列表或路径列表。`
```
repo sync [<PROJECT0> <PROJECT1> ... <PROJECTN>]
repo sync [</PATH/TO/PROJECT0> ... </PATH/TO/PROJECTN>]
```
##help
Once Repo is installed, you can find the latest documentation starting with a summary of all commands by running:`一旦Repo安装上了，你可以通过运行所有命令的摘要来找到最新的文档`

```$repo help```
You can get information about any command by running this within a Repo tree:
``
```$repo help <COMMAND>```
For example, the following command yields a description and list of options for the init argument of Repo, which initializes Repo in the current directory. (See init for more details.)

```$repo help init```

##init
```$repo init -u <URL> [<OPTIONS>]```
Installs Repo in the current directory. This creates a .repo/ directory that contains Git repositories for the Repo source code and the standard Android manifest files. The .repo/ directory also contains manifest.xml, which is a symlink to the selected manifest in the .repo/manifests/ directory. See manifest-format.txt for instructions on updating the manifest.

##Options:

-u: specify a URL from which to retrieve a manifest repository. The common manifest can be found at https://android.googlesource.com/platform/manifest

-m: select a manifest file within the repository. If no manifest name is selected, the default is default.xml.

-b: specify a revision, i.e., a particular manifest-branch.

`Note: For all remaining Repo commands, the current working directory must either be the parent directory of .repo/ or a subdirectory of the parent directory.`

##sync
```$repo sync [<PROJECT_LIST>]```
Downloads new changes and updates the working files in your local environment. If you run repo sync without any arguments, it will synchronize the files for all the projects.

When you run `repo sync`, this is what happens:

1. If the project has never been synchronized, then repo sync is equivalent to `git clone`. All branches in the remote repository are copied to the local project directory.

* If the project has already been synchronized once, then repo sync is equivalent to:

```
git remote update
git rebase origin/<BRANCH>
```
    where <BRANCH> is the currently checked-out branch in the local project directory. If the local branch is not tracking a branch in the remote repository, then no synchronization will occur for the project.

* If the git rebase operation results in merge conflicts, you will need to use the normal Git commands (for example, `git rebase --continue`) to resolve the conflicts.

After a successful `repo sync`, the code in specified projects will be up to date with the code in the remote repository.

Options:

-d: switch specified projects back to the manifest revision. Helpful if the project is currently on a topic branch, but the manifest revision is temporarily needed.

-s: sync to a known good build as specified by the manifest-server element in the current manifest.

-f: proceed with syncing other projects even if a project fails to sync.

##upload
```$repo upload [<PROJECT_LIST>]```
For the specified projects, Repo compares the local branches to the remote branches updated during the last repo sync. Repo will prompt you to select one or more of the branches that have not yet been uploaded for review.

After you select one or more branches, all commits on the selected branches are transmitted to Gerrit over an HTTPS connection. You will need to configure an HTTPS password to enable upload authorization. Visit the Password Generator to generate a new username/password pair to use over HTTPS.

When Gerrit receives the object data over its server, it will turn each commit into a change so that reviewers can comment on each commit individually. To combine several "checkpoint" commits together into a single commit, use git rebase -i before you run repo upload.

If you run repo upload without any arguments, it will search all the projects for changes to upload.

To make edits to changes after they have been uploaded, you should use a tool like git rebase -i or git commit --amend to update your local commits. After your edits are complete:

Make sure the updated branch is the currently checked out branch.

For each commit in the series, enter the Gerrit change ID inside the brackets:

```
# Replacing from branch foo
[ 3021 ] 35f2596c Refactor part of GetUploadableBranches to lookup one specific...
[ 2829 ] ec18b4ba Update proto client to support patch set replacments
# Insert change numbers in the brackets to add a new patch set.
# To create a new change record, leave the brackets empty.
After the upload is complete the changes will have an additional Patch Set.
```
If you only want to upload the currently checked out Git branch, you can use the flag --current-branch (or --cbr for short).

##diff
```$repo diff [<PROJECT_LIST>]```
Shows outstanding changes between commit and working tree using git diff.

##download
```$repo download <TARGET> <CHANGE>```
Downloads the specified change from the review system and makes it available in your project's local working directory.

For example, to download change 23823 into your platform/build directory:

```$repo download platform/build 23823```
A repo sync should effectively remove any commits retrieved via repo download. Or, you can check out the remote branch; e.g., git checkout m/master.

`Note: There is a slight mirroring lag between when a change is visible on the web in Gerrit and when repo download will be able to find it for all users, because of replication delays to all servers worldwide.`

##forall
```$repo forall [<PROJECT_LIST>] -c <COMMAND>```
Executes the given shell command in each project. The following additional environment variables are made available by repo forall:

REPO_PROJECT is set to the unique name of the project.

REPO_PATH is the path relative to the root of the client.

REPO_REMOTE is the name of the remote system from the manifest.

REPO_LREV is the name of the revision from the manifest, translated to a local tracking branch. Used if you need to pass the manifest revision to a locally executed git command.

REPO_RREV is the name of the revision from the manifest, exactly as written in the manifest.

Options:

-c: command and arguments to execute. The command is evaluated through /bin/sh and any arguments after it are passed through as shell positional parameters.

-p: show project headers before output of the specified command. This is achieved by binding pipes to the command's stdin, stdout, and sterr streams, and piping all output into a continuous stream that is displayed in a single pager session.

-v: show messages the command writes to stderr.

prune
repo prune [<PROJECT_LIST>]
Prunes (deletes) topics that are already merged.

start
repo start <BRANCH_NAME> [<PROJECT_LIST>]
Begins a new branch for development, starting from the revision specified in the manifest.

The <BRANCH_NAME> argument should provide a short description of the change you are trying to make to the projects.If you don't know, consider using the name default.

The <PROJECT_LIST> specifies which projects will participate in this topic branch.

Note: "." is a useful shorthand for the project in the current working directory.

status
repo status [<PROJECT_LIST>]
Compares the working tree to the staging area (index) and the most recent commit on this branch (HEAD) in each project specified. Displays a summary line for each file where there is a difference between these three states.

To see the status for only the current branch, run repo status. The status information will be listed by project. For each file in the project, a two-letter code is used:

In the first column, an uppercase letter indicates how the staging area differs from the last committed state.

letter	meaning	description
-	no change	same in HEAD and index
A	added	not in HEAD, in index
M	modified	in HEAD, modified in index
D	deleted	in HEAD, not in index
R	renamed	not in HEAD, path changed in index
C	copied	not in HEAD, copied from another in index
T	mode changed	same content in HEAD and index, mode changed
U	unmerged	conflict between HEAD and index; resolution required
In the second column, a lowercase letter indicates how the working directory differs from the index.

letter	meaning	description
-	new/unknown	not in index, in work tree
m	modified	in index, in work tree, modified
d	deleted	in index, not in work tree
Except as otherwise noted, the content of this page is licensed under the Creative Commons Attribution 3.0 License, and code samples are licensed under the Apache 2.0 License. For details, see our Site Policies. Java is a registered trademark of Oracle and/or its affiliates.

Last updated March 27, 2018.


------------------------
1. 切换分支
 > cd .repo/manifests
 > git branch -a | cut -d / -f 3
 > repo init -u https://android.googlesource.com/platform/manifest -b android-8.1.0_r23 [--config-name]
 > repo init -u https://aosp.tuna.tsinghua.edu.cn/platform/manifest -b android-8.1.0_r23 [--config-name]
 > repo sync
 > repo start android-8.0.0_r36 --all     把仓库的所有资源分支都切换至指定的分支

2. git强制回滚
 > git reset –hard origin/android-8.1.0_r23

3. repo 版本
 从https://github.com/esrlabs/git-repo下载一个版本，并把repo repo.cmd拷贝到用户PATH中，以让环境能自动识别。

4. F:\aosp>repo sync -l >> log.log
Syncing work tree:   1% (6/591)  Traceback (most recent call last):
  File "F:\aosp\.repo\repo/main.py", line 538, in <module>
    _Main(sys.argv[1:])
  File "F:\aosp\.repo\repo/main.py", line 512, in _Main
    result = repo._Run(argv) or 0
  File "F:\aosp\.repo\repo/main.py", line 185, in _Run
    result = cmd.Execute(copts, cargs)
  File "F:\aosp\.repo\repo\subcmds\sync.py", line 823, in Execute
    project.Sync_LocalHalf(syncbuf, force_sync=opt.force_sync)
  File "F:\aosp\.repo\repo\project.py", line 1377, in Sync_LocalHalf
    self._CopyAndLinkFiles()
  File "F:\aosp\.repo\repo\project.py", line 1294, in _CopyAndLinkFiles
    linkfile._Link()
  File "F:\aosp\.repo\repo\project.py", line 299, in _Link
    self.__linkIt(self.src_rel_to_dest, self.abs_dest)
  File "F:\aosp\.repo\repo\project.py", line 279, in __linkIt
    os.remove(absDest)
WindowsError: [Error 5] : u'F:\\aosp\\build/core'
尝试方案（行不通，先走注掉）：  因为build/core是个link，导致repo sync的checkout不出build/core.   把default.xml的build/core改回指定的地址。此问题只在window中存中。

5.
F:\aosp>repo sync
......
Fetching project platform/external/lz4
Fetching project repo
error: Cannot fetch repo (TypeError: unsupported operand type(s) for +: 'NoneType' and 'str')
Fetching project platform/test/vts-testcase/performance
Exception in thread Thread-467:
Traceback (most recent call last):
  File "C:\install\Python\Python27\lib\threading.py", line 801, in __bootstrap_inner
    self.run()
  File "C:\install\Python\Python27\lib\threading.py", line 754, in run
    self.__target(*self.__args, **self.__kwargs)
  File "F:\aosp\.repo\repo\subcmds\sync.py", line 272, in _FetchProjectList
    success = self._FetchHelper(opt, project, *args, **kwargs)
  File "F:\aosp\.repo\repo\subcmds\sync.py", line 316, in _FetchHelper
    prune=opt.prune)
  File "F:\aosp\.repo\repo\project.py", line 1254, in Sync_NetworkHalf
    and self._ApplyCloneBundle(initial=is_new, quiet=quiet):
  File "F:\aosp\.repo\repo\project.py", line 2090, in _ApplyCloneBundle
    bundle_url = remote.url + '/clone.bundle'
TypeError: unsupported operand type(s) for +: 'NoneType' and 'str'

Fetching projects:  26% (155/593)
error: Exited sync due to fetch errors

问题可能是 .repo目录下的repo目录版本不正确。删除后，重新搞就好了。
参见： https://android.googlesource.com/platform/external/libhevc/+/android-8.1.0_r23
------------------------
Syncing work tree:  35% (207/591)  fatal: cannot create directory at 'aux': Invalid argument
Traceback (most recent call last):
  File "F:\aosp\.repo\repo/main.py", line 538, in <module>
    _Main(sys.argv[1:])
  File "F:\aosp\.repo\repo/main.py", line 512, in _Main
    result = repo._Run(argv) or 0
  File "F:\aosp\.repo\repo/main.py", line 185, in _Run
    result = cmd.Execute(copts, cargs)
  File "F:\aosp\.repo\repo\subcmds\sync.py", line 823, in Execute
    project.Sync_LocalHalf(syncbuf, force_sync=opt.force_sync)
  File "F:\aosp\.repo\repo\project.py", line 1332, in Sync_LocalHalf
    self._InitWorkTree(force_sync=force_sync)
  File "F:\aosp\.repo\repo\project.py", line 2499, in _InitWorkTree
    raise GitError("cannot initialize work tree")
error.GitError: cannot initialize work tree

注： aux是window的保留字，所以在目录命名时，是不能使用的。  因为项目中【external/libunwind】中有个目录为aux的目录，所在被中断。
参见： 1. https://msdn.microsoft.com/en-us/library/windows/desktop/aa365247(v=vs.85).aspx
       2. https://android.googlesource.com/platform/external/libunwind/+/android-8.1.0_r23
------------------------
Syncing work tree:  32% (190/592)  fatal: This operation must be run in a work tree
Traceback (most recent call last):
  File "F:\aosp\.repo\repo/main.py", line 538, in <module>
    _Main(sys.argv[1:])
  File "F:\aosp\.repo\repo/main.py", line 512, in _Main
    result = repo._Run(argv) or 0
  File "F:\aosp\.repo\repo/main.py", line 185, in _Run
    result = cmd.Execute(copts, cargs)
  File "F:\aosp\.repo\repo\subcmds\sync.py", line 823, in Execute
    project.Sync_LocalHalf(syncbuf, force_sync=opt.force_sync)
  File "F:\aosp\.repo\repo\project.py", line 1332, in Sync_LocalHalf
    self._InitWorkTree(force_sync=force_sync)
  File "F:\aosp\.repo\repo\project.py", line 2499, in _InitWorkTree
    raise GitError("cannot initialize work tree")
error.GitError: cannot initialize work tree

可以看到F:\aosp\.repo\project-objects\platform\external\libhevc.git 目录容量为0 表明资源没有下载成功。固然要把它从资源清单中移除。
------------------------
https://android.googlesource.com/platform/manifest.git/+refs
> git clone https://android.googlesource.com/platform/manifest.git
> git tag
> git checkout android-1.6_r2

------------------------
F:\aosp>repo init -b android-8.1.0_r23
Traceback (most recent call last):
  File "F:\aosp\.repo\repo/main.py", line 538, in <module>
    _Main(sys.argv[1:])
  File "F:\aosp\.repo\repo/main.py", line 512, in _Main
    result = repo._Run(argv) or 0
  File "F:\aosp\.repo\repo/main.py", line 185, in _Run
    result = cmd.Execute(copts, cargs)
  File "F:\aosp\.repo\repo\subcmds\init.py", line 399, in Execute
    self._SyncManifest(opt)
  File "F:\aosp\.repo\repo\subcmds\init.py", line 245, in _SyncManifest
    m.MetaBranchSwitch()
  File "F:\aosp\.repo\repo\project.py", line 2927, in MetaBranchSwitch
    self.Sync_LocalHalf(syncbuf)
  File "F:\aosp\.repo\repo\project.py", line 1368, in Sync_LocalHalf
    lost = self._revlist(not_rev(revid), HEAD)
  File "F:\aosp\.repo\repo\project.py", line 2515, in _revlist
    return self.work_git.rev_list(*a, **kw)
  File "F:\aosp\.repo\repo\project.py", line 2714, in rev_list
    (self._project.name, str(args), p.stderr))
error.GitError: manifests rev-list (u'^19f8c1ff3dd6b6e4fd9795b09f486f66f7000254', 'HEAD', '--'): fatal: bad revision 'HEAD'

当使用 > repo init -b android-8.1.0_r23  切换分支时，会出现git 关联错误问题。

> F:\aosp\.repo>cd manifests
> F:\aosp\.repo\manifests>git reset --hard origin/android-8.1.0_r23

------------------------
error: .repo/manifests/: contains uncommitted changes
当进行切换android版本后，又对manifest/default.xml进行修改了，再进行repo sync时，就会出现此错误提示
处理方案：
> cd .repo/manifests
> git checkout default.xml 来还原它的版本。
> repo sync   进行一次短暂的同步后，快速中断。再把需要修改的内容修改过来。
> repo sync    此时就能正常的同步了。
------------------------
.repo/manifest/default.xml 以下三个在清华镜像中下载不了。

<!--<project path="device/generic/common" name="device/generic/common" groups="pdk" />-->
<!--<project path="packages/inputmethods/OpenWnn" name="platform/packages/inputmethods/OpenWnn" groups="pdk-fs" />-->
<!--<project path="prebuilts/gcc/darwin-x86/arm/arm-eabi-4.8" name="platform/prebuilts/gcc/darwin-x86/arm/arm-eabi-4.8" groups="pdk,darwin,arm" clone-depth="1" />-->

> 出现以上三个无法下载时，把其 symlinks=false参数删除掉，或把其.git目录删除掉就能下载了。



以下资源会导致window下checkout代码时出错的清单
<!--<linkfile src="core" dest="build/core" />
    <linkfile src="target" dest="build/target" />
    <linkfile src="tools" dest="build/tools" />-->

<!--<linkfile src="root.bp" dest="Android.bp" />
    <linkfile src="bootstrap.bash" dest="bootstrap.bash" />-->

<!--<project path="external/libhevc" name="platform/external/libhevc" groups="pdk" />-->

<!--<project path="external/libunwind" name="platform/external/libunwind" groups="pdk" />-->

<!--<project path="frameworks/base" name="platform/frameworks/base" groups="pdk-cw-fs,pdk-fs" />-->

<!--<project path="libcore" name="platform/libcore" groups="pdk" />-->