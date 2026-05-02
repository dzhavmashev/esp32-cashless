// Function : FUN_400f2488
// Address  : 0x400f2488
// Size     : 542 bytes


byte FUN_400f2488(uint param_1,char param_2,char param_3,char param_4,char param_5)

{
  byte bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  
  if (param_1 < 3) {
    iVar5 = (int)param_2;
    bVar1 = 1;
    if (-1 < iVar5) {
      iVar4 = FUN_400f6e54(*(undefined1 *)(param_1 * 0x20 + 0x3ffbdbd4),0xffffffff,iVar5,0xffffffff)
      ;
      bVar1 = 1;
      if (iVar4 == 0) {
        *(char *)(param_1 * 0x20 + 0x3ffbdbdc) = param_2;
      }
      else {
        uVar6 = func_0x40085c04();
        uVar2 = FUN_401847ec("t_intr)");
        uVar3 = (*(code *)&SUB_4000cff8)((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),1000,0);
        FUN_400f22b8("to %u\r\n",uVar3,uVar2,0x95,"rtBegin",param_1,iVar5);
        bVar1 = 0;
      }
    }
    iVar5 = (int)param_3;
    if (-1 < iVar5) {
      iVar4 = FUN_400f6e54(*(undefined1 *)(param_1 * 0x20 + 0x3ffbdbd4),iVar5,0xffffffff,0xffffffff)
      ;
      if (iVar4 == 0) {
        *(char *)(param_1 * 0x20 + 0x3ffbdbdd) = param_3;
      }
      else {
        uVar6 = func_0x40085c04();
        uVar2 = FUN_401847ec("t_intr)");
        uVar3 = (*(code *)&SUB_4000cff8)((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),1000,0);
        FUN_400f22b8("in %d\r\n",uVar3,uVar2,0x9f,"rtBegin",param_1,iVar5);
      }
      bVar1 = bVar1 & iVar4 == 0;
    }
    iVar5 = (int)param_4;
    if (-1 < iVar5) {
      iVar4 = FUN_400f6e54(*(undefined1 *)(param_1 * 0x20 + 0x3ffbdbd4),0xffffffff,0xffffffff,
                           0xffffffff,iVar5);
      if (iVar4 == 0) {
        *(char *)(param_1 * 0x20 + 0x3ffbdbde) = param_4;
      }
      else {
        uVar6 = func_0x40085c04();
        uVar2 = FUN_401847ec("t_intr)");
        uVar3 = (*(code *)&SUB_4000cff8)((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),1000,0);
        FUN_400f22b8("in %d\r\n",uVar3,uVar2,0xa9,"rtBegin",param_1,iVar5);
      }
      bVar1 = bVar1 & iVar4 == 0;
    }
    iVar5 = (int)param_5;
    if (-1 < iVar5) {
      iVar4 = FUN_400f6e54(*(undefined1 *)(param_1 * 0x20 + 0x3ffbdbd4),0xffffffff,0xffffffff,iVar5)
      ;
      if (iVar4 == 0) {
        *(char *)(param_1 * 0x20 + 0x3ffbdbdf) = param_5;
      }
      else {
        uVar6 = func_0x40085c04();
        uVar2 = FUN_401847ec("t_intr)");
        uVar3 = (*(code *)&SUB_4000cff8)((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),1000,0);
        FUN_400f22b8("in %d\r\n",uVar3,uVar2,0xb3,"rtBegin",param_1,iVar5);
      }
      bVar1 = bVar1 & iVar4 == 0;
    }
  }
  else {
    uVar6 = func_0x40085c04();
    uVar2 = FUN_401847ec("t_intr)");
    uVar3 = (*(code *)&SUB_4000cff8)((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),1000,0);
    FUN_400f22b8("io_ll.h",uVar3,uVar2,0x85,"rtBegin",2);
    bVar1 = 0;
  }
  return bVar1;
}

