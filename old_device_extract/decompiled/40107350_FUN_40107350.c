// Function : FUN_40107350
// Address  : 0x40107350
// Size     : 156 bytes


undefined4 FUN_40107350(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 4) == param_3) {
    iVar3 = *(int *)(param_1 + 8);
    *(undefined4 *)(&DAT_3ffc58b0 + iVar3 * 4) = param_2;
    if (iVar3 == 0) {
      uVar1 = 0x40107264;
    }
    else {
      uVar1 = 0x40107280;
      if (iVar3 != 1) {
        memw();
        uVar1 = (*(code *)&SUB_40094b80)();
        FUN_4012113c(1,"wifi_ap","tif=%p\n",uVar1,"wifi_ap",iVar3);
        return 0x106;
      }
    }
    *(int *)(&DAT_3ffc58a8 + iVar3 * 4) = param_3;
    memw();
    iVar2 = FUN_401471ac(iVar3,uVar1);
    uVar1 = 0;
    if (iVar2 != 0) {
      uVar1 = (*(code *)&SUB_40094b80)();
      memw();
      FUN_4012113c(1,"wifi_ap"," if=%d\n",uVar1,"wifi_ap",iVar3,iVar2);
      uVar1 = 0x103;
    }
  }
  else {
    uVar1 = (*(code *)&SUB_40094b80)();
    memw();
    FUN_4012113c(1,"wifi_ap","handle\n",uVar1,"wifi_ap",param_3,*(undefined4 *)(param_1 + 4));
    uVar1 = 0x102;
  }
  return uVar1;
}

