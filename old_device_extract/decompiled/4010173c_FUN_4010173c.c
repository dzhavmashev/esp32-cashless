// Function : FUN_4010173c
// Address  : 0x4010173c
// Size     : 70 bytes


undefined4 FUN_4010173c(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((param_1 == 0) || (param_2 == (undefined4 *)0x0)) {
    uVar1 = 0x102;
  }
  else {
    iVar2 = *(int *)(param_1 + 0x10);
    if ((iVar2 == 0) || ((*(byte *)(iVar2 + 0xeb) & 1) == 0)) {
      (*(code *)&SUB_4008b3d0)(param_2,*(undefined4 *)(param_1 + 8),0xc);
    }
    else {
      *param_2 = *(undefined4 *)(iVar2 + 4);
      param_2[1] = *(undefined4 *)(iVar2 + 0x1c);
      param_2[2] = *(undefined4 *)(iVar2 + 0x34);
    }
    uVar1 = 0;
  }
  memw();
  return uVar1;
}

