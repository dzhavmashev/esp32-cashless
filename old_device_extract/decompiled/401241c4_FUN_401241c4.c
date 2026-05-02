// Function : FUN_401241c4
// Address  : 0x401241c4
// Size     : 132 bytes


int FUN_401241c4(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = param_2 + 0xa8;
  iVar3 = param_2 + 0x24;
  (*(code *)&SUB_4008b3d0)(iVar2,iVar3,0x20);
  FUN_40185048(iVar3,0x20);
  iVar1 = FUN_40124154(param_2 + 0x48,"Counter",param_1 + 0x5c,iVar2,
                       param_2 + *(int *)(param_2 + 0x18) * 0x20 + 0x48,
                       *(undefined4 *)(param_2 + 0x14));
  iVar1 = iVar1 >> 0x1f;
  if (*(int *)(param_1 + 0x44) != 0) {
    memw();
    (*(code *)&SUB_4008b3d0)(iVar2,iVar3,0x20);
    FUN_40185048(iVar3,0x20);
    iVar2 = FUN_40124154(param_2 + 0x48,"pansion",param_1 + 0x5c,iVar2,
                         param_2 + (*(int *)(param_2 + 0xf4) + 9) * 0x10 + 4,0x10);
    if (iVar2 < 0) {
      iVar1 = -1;
    }
  }
  return iVar1;
}

