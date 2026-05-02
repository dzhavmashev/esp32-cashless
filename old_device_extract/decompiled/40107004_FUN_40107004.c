// Function : FUN_40107004
// Address  : 0x40107004
// Size     : 74 bytes


undefined4 FUN_40107004(int param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_1 == 0) || (1 < param_2)) {
    uVar2 = 0x102;
  }
  else {
    *(int *)(&DAT_3ffc58a0 + param_2 * 4) = param_1;
    memw();
    iVar1 = FUN_40107300(param_2);
    if (iVar1 == 0) {
      uVar2 = (*(code *)&SUB_40094b80)();
      FUN_4012113c(1,"I_EVENT","ith %d\n",uVar2,"I_EVENT");
      uVar2 = 0xffffffff;
    }
    else {
      uVar2 = FUN_401014d8(param_1,iVar1);
    }
  }
  return uVar2;
}

