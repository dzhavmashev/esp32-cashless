// Function : FUN_400f26ac
// Address  : 0x400f26ac
// Size     : 475 bytes


uint FUN_400f26ac(uint param_1,char param_2,char param_3,char param_4,char param_5)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  undefined8 uVar13;
  
  param_1 = param_1 & 0xff;
  if (param_1 < 3) {
    iVar10 = param_1 * 0x20;
    if (*(int *)(iVar10 + 0x3ffbdbd0) != 0) {
      do {
        iVar7 = func_0x40090018(*(int *)(iVar10 + 0x3ffbdbd0),0xffffffff);
      } while (iVar7 != 1);
    }
    bVar1 = false;
    iVar7 = (int)param_2;
    uVar11 = 1;
    if ((-1 < iVar7) && (*(char *)(iVar10 + 0x3ffbdbdc) != iVar7)) {
      uVar11 = FUN_400f22e0(param_1,(int)*(char *)(iVar10 + 0x3ffbdbdc),0xffffffff,0xffffffff);
      bVar1 = true;
    }
    bVar2 = false;
    if ((-1 < param_3) && ((int)*(char *)(iVar10 + 0x3ffbdbdd) != (int)param_3)) {
      uVar8 = FUN_400f22e0(param_1,0xffffffff,(int)*(char *)(iVar10 + 0x3ffbdbdd),0xffffffff);
      uVar11 = uVar11 & uVar8 & 0xff;
      bVar2 = true;
    }
    iVar9 = (int)param_4;
    bVar3 = false;
    if ((-1 < iVar9) && (*(char *)(iVar10 + 0x3ffbdbde) != iVar9)) {
      uVar8 = FUN_400f22e0(param_1,0xffffffff,0xffffffff);
      uVar11 = uVar11 & uVar8 & 0xff;
      bVar3 = true;
    }
    iVar10 = (int)param_5;
    iVar12 = param_1 * 0x20;
    bVar4 = false;
    if ((-1 < iVar10) && (*(char *)(iVar12 + 0x3ffbdbdf) != iVar10)) {
      uVar8 = FUN_400f22e0(param_1,0xffffffff,0xffffffff);
      uVar11 = uVar11 & uVar8 & 0xff;
      bVar4 = true;
    }
    if (bVar1) {
      uVar8 = FUN_400f2488(param_1,iVar7,0xffffffff,0xffffffff);
      uVar11 = uVar11 & uVar8 & 0xff;
    }
    if (bVar2) {
      uVar8 = FUN_400f2488(param_1,0xffffffff,(int)param_3,0xffffffff);
      uVar11 = uVar11 & uVar8 & 0xff;
    }
    if (bVar3) {
      uVar8 = FUN_400f2488(*(undefined1 *)(iVar12 + 0x3ffbdbd4),0xffffffff,0xffffffff,iVar9);
      uVar11 = uVar11 & uVar8 & 0xff;
    }
    if (bVar4) {
      uVar8 = FUN_400f2488(*(undefined1 *)(iVar12 + 0x3ffbdbd4),0xffffffff,0xffffffff,0xffffffff,
                           iVar10);
      uVar11 = uVar11 & uVar8 & 0xff;
    }
    iVar10 = *(int *)(param_1 * 0x20 + 0x3ffbdbd0);
    if (iVar10 != 0) {
      func_0x4008fac0(iVar10,0,0);
    }
    if (uVar11 == 0) {
      uVar13 = func_0x40085c04();
      uVar5 = FUN_401847ec("t_intr)");
      uVar6 = (*(code *)&SUB_4000cff8)((int)uVar13,(int)((ulonglong)uVar13 >> 0x20),1000,0);
      FUN_400f22b8("in %d\r\n",uVar6,uVar5,0x11d,"unc_sel",param_1);
    }
  }
  else {
    uVar13 = func_0x40085c04();
    uVar5 = FUN_401847ec("t_intr)");
    uVar6 = (*(code *)&SUB_4000cff8)((int)uVar13,(int)((ulonglong)uVar13 >> 0x20),1000,0);
    FUN_400f22b8("io_ll.h",uVar6,uVar5,0xef,"unc_sel",2);
    uVar11 = 0;
  }
  return uVar11;
}

