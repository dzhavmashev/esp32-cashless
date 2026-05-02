// Function : FUN_400e9f60
// Address  : 0x400e9f60
// Size     : 104 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_400e9f60(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  if (_DAT_3ffc51dc == 0) {
    uVar3 = func_0x40085c04();
    uVar1 = FUN_401847ec(&DAT_3f40931c);
    uVar2 = (*(code *)&SUB_4000cff8)((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),1000,0);
    FUN_4012105c("icate\r\n",uVar2,uVar1,0xb8,"allback");
  }
  else if (param_1 != 0) {
    FUN_4014471c(0x3ffc51e8);
    (*(code *)&LAB_4018598b_1)(param_1,0x3ffc51e8,0);
    FUN_4018595c(param_1,0x400e9e3c,0);
  }
  return 0;
}

