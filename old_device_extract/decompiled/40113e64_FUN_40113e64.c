// Function : FUN_40113e64
// Address  : 0x40113e64
// Size     : 138 bytes


/* WARNING: Removing unreachable block (ram,0x40113e85) */

void FUN_40113e64(int param_1)

{
  if (param_1 == 0) goto LAB_40113edd;
  if (*(char *)(param_1 + 0x14) == '.') {
    *(undefined1 *)(param_1 + 0x2c) = 0;
    memw();
    *(undefined4 *)(param_1 + 0x18) = 0;
LAB_40113ea2:
    *(undefined4 *)(param_1 + 0x24) = 0;
    *(undefined4 *)(param_1 + 0x20) = 0;
    *(undefined4 *)(param_1 + 0x1c) = 0;
    memw();
    *(undefined1 *)(param_1 + 0x28) = 0;
    memw();
    memw();
  }
  else {
    *(undefined4 *)(param_1 + 0x18) = 0;
    if (*(char *)(param_1 + 0x2c) != '\x06') {
      *(undefined1 *)(param_1 + 0x2c) = 0;
      memw();
      memw();
      goto LAB_40113ea2;
    }
    *(undefined4 *)(param_1 + 0x1c) = 0;
    *(undefined4 *)(param_1 + 0x20) = 0;
    *(undefined4 *)(param_1 + 0x24) = 0;
    *(undefined1 *)(param_1 + 0x28) = 0;
    *(undefined1 *)(param_1 + 0x2c) = 6;
  }
  *(undefined2 *)(param_1 + 0x3c) = 0;
  *(undefined1 *)(param_1 + 0x30) = 0;
  memw();
  *(byte *)(param_1 + 0x38) = *(byte *)(param_1 + 0x38) & 0xfb;
  memw();
LAB_40113edd:
  memw();
  return;
}

