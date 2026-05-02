// Function : FUN_4011711c
// Address  : 0x4011711c
// Size     : 64 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4011711c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = _DAT_3ffc83b8;
  if (_DAT_3ffc83b8 == 0) {
    (*(code *)&SUB_40094c54)(" header",0x13a,"d_netif","icmp6.c");
  }
  iVar2 = FUN_401174f8(iVar1,&DAT_3ffc83cc);
  if (iVar2 != 0) {
    memw();
    FUN_40117028(param_1,param_2,param_3,param_4,iVar2,&DAT_3ffc83cc,iVar1);
  }
  return;
}

