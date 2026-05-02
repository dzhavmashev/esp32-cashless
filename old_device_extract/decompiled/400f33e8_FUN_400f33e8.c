// Function : FUN_400f33e8
// Address  : 0x400f33e8
// Size     : 715 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_400f33e8(uint param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  undefined8 uVar6;
  undefined1 auStack_40 [4];
  int iStack_3c;
  uint uStack_38;
  uint uStack_34;
  undefined1 auStack_30 [4];
  int iStack_2c;
  uint uStack_28;
  uint uStack_24;
  
  uVar1 = (*(code *)&SUB_4008dae8)();
  if (uVar1 != 0) {
    if (uVar1 < 0x28) {
      if ((param_1 < uVar1) && (uVar1 >> 1 != param_1)) {
        uVar6 = (*(code *)&SUB_40085bfc)();
        uVar2 = FUN_401847ec("def");
        uVar3 = (*(code *)&SUB_4000cff8)((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),1000,0);
        FUN_4012105c("g=%8p\r\n",uVar3,uVar2,0xab,"u MHz\r\n",param_1,uVar1,uVar1 >> 1);
        return 0;
      }
    }
    else if (((param_1 < uVar1) && (uVar1 >> 1 != param_1)) && (uVar1 >> 2 != param_1)) {
      uVar6 = (*(code *)&SUB_40085bfc)();
      uVar2 = FUN_401847ec("def");
      uVar3 = (*(code *)&SUB_4000cff8)((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),1000,0);
      FUN_4012105c("u MHz\r\n",uVar3,uVar2,0xaf,"u MHz\r\n",param_1,uVar1,uVar1 >> 1,uVar1 >> 2);
      return 0;
    }
  }
  if ((uVar1 < param_1) && (param_1 != 0xf0)) {
    if ((param_1 != 0xa0) && (param_1 != 0x50)) {
      if (uVar1 < 0x28) {
        uVar6 = (*(code *)&SUB_40085bfc)();
        uVar2 = FUN_401847ec("def");
        uVar3 = (*(code *)&SUB_4000cff8)((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),1000,0);
        FUN_4012105c("g=%8p\r\n",uVar3,uVar2,0xb8,"u MHz\r\n",param_1,uVar1,uVar1 >> 1);
        return 0;
      }
      uVar6 = (*(code *)&SUB_40085bfc)();
      uVar2 = FUN_401847ec("def");
      uVar3 = (*(code *)&SUB_4000cff8)((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),1000,0);
      FUN_4012105c("u MHz\r\n",uVar3,uVar2,0xb6,"u MHz\r\n",param_1,uVar1,uVar1 >> 1,uVar1 >> 2);
      return 0;
    }
  }
  else if ((param_1 == 0xf0) &&
          ((memw(), (_DAT_3ff5a00c & 0x2000) != 0 && (memw(), (_DAT_3ff5a00c & 0x1000) != 0)))) {
    uVar6 = (*(code *)&SUB_40085bfc)();
    uVar2 = FUN_401847ec("def");
    uVar3 = (*(code *)&SUB_4000cff8)((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),1000,0);
    FUN_4012105c("u MHz\r\n",uVar3,uVar2,0xc2,"u MHz\r\n");
    param_1 = 0xa0;
  }
  (*(code *)&SUB_4008db6c)(auStack_30);
  if (uStack_24 != param_1) {
    iVar4 = (*(code *)&SUB_4008db10)(param_1,auStack_40);
    if (iVar4 == 0) {
      uVar6 = (*(code *)&SUB_40085bfc)();
      uVar2 = FUN_401847ec("def");
      uVar3 = (*(code *)&SUB_4000cff8)((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),1000,0);
      FUN_4012105c("0MHz.\r\n",uVar3,uVar2,0xcf,"u MHz\r\n",param_1);
      return 0;
    }
    uVar1 = 80000000;
    if (uStack_24 < 0x50) {
      uVar1 = (uint)(iStack_2c * 1000000) / uStack_28;
    }
    uVar5 = 80000000;
    if (uStack_34 < 0x50) {
      uVar5 = (uint)(iStack_3c * 1000000) / uStack_38;
    }
    if (_DAT_3ffc554c != 0) {
      FUN_400f3384(0,uVar1,uVar5);
    }
    (*(code *)&SUB_4008ddac)(auStack_40);
    if (uVar5 != uVar1) {
      (*(code *)&SUB_4008dbfc)(uVar5);
      (*(code *)&SUB_40085d14)(uVar5 / 1000000);
    }
    _DAT_3ffc6760 = uVar5;
    if (0x4f < uStack_34) {
      _DAT_3ffc6760 = uStack_34 * 1000000;
    }
    _DAT_3ffc6760 = _DAT_3ffc6760 / 1000;
    if (_DAT_3ffc554c != 0) {
      FUN_400f3384(1,uVar1,uVar5);
      return iVar4;
    }
  }
  return 1;
}

