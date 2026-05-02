// Function : FUN_4012232c
// Address  : 0x4012232c
// Size     : 66 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4012232c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _DAT_3ffc72e8;
  *(undefined4 *)(param_1 + 4) = _DAT_3ffc72e0;
  memw();
  iVar1 = (**(code **)(iVar1 + 8))(*(undefined4 *)(iVar1 + 0x10),param_1,0x20);
  uVar2 = 0x20;
  if (iVar1 != 0) {
    uVar2 = (*(code *)&SUB_40094ae8)();
    (*(code *)&SUB_40007d54)(0x3ffc1663,uVar2,0x3ffc16cf,"ve_task",0x97,iVar1);
    uVar2 = 0xfffffffe;
  }
  return uVar2;
}

