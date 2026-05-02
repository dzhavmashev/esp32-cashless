// Function : FUN_40100b38
// Address  : 0x40100b38
// Size     : 48 bytes


undefined4 FUN_40100b38(int param_1)

{
  if (((*(int *)(param_1 + 0x10) != 0) && (*(char *)(param_1 + 0x3c) != '\x01')) &&
     (**(int **)(param_1 + 8) != 0)) {
    *(undefined1 *)(param_1 + 0x3c) = 1;
    memw();
    memw();
    FUN_40113258(120000,&LAB_4010109c,param_1);
  }
  return 0;
}

