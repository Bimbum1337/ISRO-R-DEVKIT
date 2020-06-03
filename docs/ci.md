# Continuous Integration (CI)

Continuous Integration (CI) allows us to create a reproduceable build environment, build your code in it and check for errors and perform tests. Every Pull Request will be build by the CI to ensure the code you are contributing works. 

The CI requires a so called runner to work. Gitlab comes with free runners. These are based on Linux and can not run Visual Studio (we have tested this in [#4](https://gitlab.com/florian0/sro_devkit/issues/4), its horrible). The main repository is equipped with a runner hosted by us. It is modified for usage with the [Hetzner Cloud](https://www.hetzner.de/cloud). This allows us to create the required windows build environment on demand without having to host a full windows server. The use of our CI is completely free.

If you're interested in the gitlab-runner project, you can find it here: https://gitlab.com/florian0/gitlab-runner/tree/hcloud-executor

## Using our CI

The CI runner is only available for this repository. If you click on *Fork*, the project gets copied to your account and the CI will be run from your own repository which doesn't have our runner.

It is easier to work in our repoistory. To do so, you need to *Request access*.

### Rules for the CI on our repository

* Don't push too often. Every push triggers a new CI job. Only push if you want to run the CI.
* Don't touch `gitlab-ci.yml`. Just don't.
* Don't abuse the CI.

If you happen to violate these rules, we will consider removing your access rights.

## Using your own CI ...

You can make the CI run in our own repository. Just install the [gitlab-runner](https://docs.gitlab.com/runner/) on our own PC and register it to your repository.

### ... on VirtualBox!

VirtualBox allows you to create a virtual machine on your home computer. GitLab Runner will create a virtual machine from a snapshot, run the build and delete the virtual machine afterwards.

In general, the official guide works for us: https://docs.gitlab.com/runner/executors/virtualbox.html. Make sure to follow every step and don't skip the *Checklist for Windows VMs*.

#### Preparing the VM

Short list of additional software to be installed:

* Visual Studio 2005
* CMake

Create a new virtual machine and install a windows version of your choice. Windows 7 and above should be fine. You don't need to activate it. The nag does not matter. Follow the steps to setup [Visual Studio 2005](build-environment/visual-studio/2005.md) and [CMake](build-environment/cmake.md).

#### Validate your environment

Make sure that the commands `cmake`, `git` and `gitlab-runner` are executable from the Cygwin Terminal.

After validating, shutdown the VM and make a snapshot of the current state.
