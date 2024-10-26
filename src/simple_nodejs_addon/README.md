# Simple Nodejs Addon in C

## Steps

**Install Node-GYP**

```bash
npm install -g node-gyp
```

**Setup Dir**

```bash
mkdir my-c-addon
cd my-c-addon
```

**Setup Files**

```bash
npm init -y

touch binding.gyp

touch addon.c
```

**Use the Compiled C Module in Node.js**

```bash
node-gyp clean
node-gyp configure
node-gyp build

node index.js
```
