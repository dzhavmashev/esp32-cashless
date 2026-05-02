// Function : FUN_40106fa8
// Address  : 0x40106fa8
// Size     : 92 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40106fa8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = _DAT_3ffc58a0;
  if (_DAT_3ffc58a0 != 0) {
    uVar1 = FUN_40184e30(_DAT_3ffc58a0);
    iVar2 = FUN_4018525c();
    if ((iVar2 == 0) && (iVar3 = FUN_40107350(uVar1,0x40184e64,iVar3), iVar3 != 0)) {
      uVar4 = (*(code *)&SUB_40094b80)();
      memw();
      FUN_4012113c(1,"I_EVENT","ith %d\n",uVar4,"I_EVENT",uVar1,iVar3);
    }
    else {
      FUN_40100444(_DAT_3ffc58a0,param_2,param_3,param_4);
    }
  }
  return;
}

