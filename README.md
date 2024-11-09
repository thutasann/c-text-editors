# Building Tools in C

In this repo, Tools, Native Libraries, Addons will be created with C.

## Table of Contents

| Topic     | Source                     |
| --------- | -------------------------- |
| Notes     | [Source](./docs/README.md) |
| Scripts   | [Source](#scripts)         |
| Resources | [Source](#resources)       |

## Tools

| Tools                   | Source                                  |
| ----------------------- | --------------------------------------- |
| First Text Editor       | [Source](./src/first-editor)            |
| Simple Nodejs Addon     | [Source](./src/simple_nodejs_addon)     |
| Web Server from scratch | [Source](./src/web_server_from_scratch) |

## Scripts

**Run Simple GUI Text Editor:**

```bash
make clean && make run PROJECT=first-editor
```

**display the exit status of the last executed command**

```bash
echo $?
```

## Resources

- [Article](https://viewsourcecode.org/snaptoken/kilo/)
- [Ncurses](https://ftp.gnu.org/pub/gnu/ncurses/)
