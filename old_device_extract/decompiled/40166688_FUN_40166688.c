// Function : FUN_40166688
// Address  : 0x40166688
// Size     : 56 bytes


undefined4 FUN_40166688(int *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(*param_1 + 4) + 4);
  if ((**(uint **)(*param_1 + 0x2c) & 0x40000) != 0) {
    iVar1 = iVar1 + 4;
  }
  memw();
  *(uint *)((uint)*(byte *)(param_1 + 1) * -0x3c + 0x3ff74268) =
       CONCAT22(*(undefined2 *)(iVar1 + 2),*(undefined2 *)(iVar1 + 2));
  memw();
  return 0;
}

