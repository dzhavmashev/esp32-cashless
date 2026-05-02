// Function : FUN_400f2888
// Address  : 0x400f2888
// Size     : 157 bytes


void FUN_400f2888(uint param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  
  param_1 = param_1 & 0xff;
  if (param_1 < 3) {
    iVar4 = param_1 * 0x20;
    if (*(int *)(iVar4 + 0x3ffbdbd0) != 0) {
      do {
        iVar3 = func_0x40090018(*(int *)(iVar4 + 0x3ffbdbd0),0xffffffff);
      } while (iVar3 != 1);
    }
    FUN_400f22e0(param_1,(int)*(char *)(iVar4 + 0x3ffbdbdc),(int)*(char *)(iVar4 + 0x3ffbdbdd),
                 (int)*(char *)(iVar4 + 0x3ffbdbde),(int)*(char *)(iVar4 + 0x3ffbdbdf));
    iVar3 = FUN_400f7cd0(param_1);
    if (iVar3 != 0) {
      FUN_400f7960(param_1);
    }
    if (*(int *)(iVar4 + 0x3ffbdbd0) != 0) {
      func_0x4008fac0(*(int *)(iVar4 + 0x3ffbdbd0),0,0);
    }
  }
  else {
    uVar5 = func_0x40085c04();
    uVar1 = FUN_401847ec("t_intr)");
    uVar2 = (*(code *)&SUB_4000cff8)((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),1000,0);
    FUN_400f22b8("io_ll.h",uVar2,uVar1,0x209,"hTxOnly",2);
  }
  return;
}

