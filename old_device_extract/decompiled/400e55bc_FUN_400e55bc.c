// Function : FUN_400e55bc
// Address  : 0x400e55bc
// Size     : 70 bytes


undefined4 FUN_400e55bc(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = (*(code *)&LAB_40170217_1)(0x60);
  FUN_400e99e8();
  *(undefined4 *)(param_1 + 0x1bc) = uVar1;
  FUN_400e6f20(*(undefined4 *)(param_1 + 0xf8),uVar1);
  FUN_400e5484(param_1);
  iVar2 = param_1 + 0x1c;
  if ((*(byte *)(param_1 + 0x2b) & 0x80) == 0) {
    iVar2 = *(int *)(param_1 + 0x1c);
  }
  FUN_400f06a4(0x3ffc5490,"needed.",iVar2);
  return 1;
}

