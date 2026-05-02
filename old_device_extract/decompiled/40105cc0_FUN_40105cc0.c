// Function : FUN_40105cc0
// Address  : 0x40105cc0
// Size     : 48 bytes


undefined4 FUN_40105cc0(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_40159ff8();
  (*(code *)&SUB_4008b530)(param_3,0,0x24);
  uVar2 = 0xffffffff;
  if ((param_2 != 0) && ((iVar1 != 1 || ((*(byte *)(param_1 + 2) & 0x20) != 0)))) {
    uVar2 = 0;
    *(byte *)(param_3 + 0x20) = *(byte *)(param_1 + 2);
    memw();
  }
  memw();
  return uVar2;
}

