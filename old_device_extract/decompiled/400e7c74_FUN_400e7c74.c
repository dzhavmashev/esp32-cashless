// Function : FUN_400e7c74
// Address  : 0x400e7c74
// Size     : 874 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400e7c74(void)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  char *pcVar8;
  undefined4 uVar9;
  undefined8 uVar10;
  undefined1 auStack_2c [8];
  undefined4 *puStack_24;
  
  puVar5 = (undefined4 *)&DAT_3ffc5708;
  puVar6 = (undefined4 *)&DAT_3ffc517f;
  memw();
  memw();
  puStack_24 = _DAT_3ffc5708;
  if (DAT_3ffc517f == '\0') {
    DAT_3ffc517f = 1;
    iVar2 = FUN_4011ecfc(auStack_2c);
    if (iVar2 == 0) {
      FUN_4011ec78(auStack_2c);
    }
    puVar6 = (undefined4 *)&DAT_3ffc517f;
    puVar5 = (undefined4 *)&DAT_3ffc5708;
    iVar2 = FUN_4010112c();
    DAT_3ffc517f = iVar2 == 0;
    if ((bool)DAT_3ffc517f) {
      uVar1 = 0;
      puVar5 = (undefined4 *)&DAT_3ffc5708;
      puVar6 = (undefined4 *)&DAT_3ffc517f;
      if (_DAT_3ffc5180 != 0) goto LAB_400e7d1c;
      iVar2 = func_0x4008f3cc();
      puVar5 = (undefined4 *)&DAT_3ffc5708;
      puVar7 = (undefined4 *)&DAT_3ffc517f;
      _DAT_3ffc5180 = iVar2;
      if (iVar2 != 0) goto LAB_400e7d16;
      uVar10 = func_0x40085c04();
      uVar3 = FUN_401847ec("02X%02X");
      uVar4 = (*(code *)&SUB_4000cff8)((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),1000,0);
      puVar5 = (undefined4 *)&DAT_3ffc5708;
      puVar6 = (undefined4 *)&DAT_3ffc517f;
      pcVar8 = " : %s\r\n";
      uVar9 = 0x22e;
      goto LAB_400e7cfa;
    }
    uVar10 = func_0x40085c04();
    uVar3 = FUN_401847ec("02X%02X");
    uVar4 = (*(code *)&SUB_4000cff8)((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),1000,0);
    FUN_4012105c("iled!\r\n",uVar4,uVar3,0x275,"nt_task");
  }
  do {
    puVar7 = puStack_24;
    uVar1 = *(undefined1 *)puVar6;
    memw();
    memw();
    puVar5 = (undefined4 *)*puVar5;
    if (puStack_24 == puVar5) {
      return;
    }
    iVar2 = func_0x40082ecc();
LAB_400e7d16:
    func_0x4008f558(iVar2,0x2000);
    puVar6 = puVar7;
LAB_400e7d1c:
    if ((_DAT_3ffc5188 == 0) && (_DAT_3ffc5188 = func_0x4008f998(0x20,4), _DAT_3ffc5188 == 0)) {
      uVar10 = func_0x40085c04();
      uVar3 = FUN_401847ec("02X%02X");
      uVar4 = (*(code *)&SUB_4000cff8)((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),1000,0);
      uVar9 = 0x236;
      pcVar8 = "iled!\r\n";
LAB_400e7cfa:
      FUN_4012105c(pcVar8,uVar4,uVar3,uVar9,"vent_cb");
    }
    else {
      iVar2 = (*(code *)&LAB_4018cf47_1)();
      uVar1 = iVar2 != 0 && iVar2 != 0x103;
      if (iVar2 != 0 && iVar2 != 0x103) {
        uVar10 = func_0x40085c04();
        uVar3 = FUN_401847ec("02X%02X");
        uVar4 = (*(code *)&SUB_4000cff8)((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),1000,0);
        uVar9 = 0x23d;
        pcVar8 = "iled!\r\n";
        goto LAB_400e7cfa;
      }
      if ((_DAT_3ffc5184 == 0) &&
         (FUN_400f1a68(0x400e8fe8,"iled!\r\n",0x1000,0,0x13,&DAT_3ffc5184,1), _DAT_3ffc5184 == 0)) {
        uVar10 = func_0x40085c04();
        uVar3 = FUN_401847ec("02X%02X");
        uVar4 = (*(code *)&SUB_4000cff8)((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),1000,0);
        uVar9 = 0x244;
        pcVar8 = "_events";
        goto LAB_400e7cfa;
      }
      iVar2 = (*(code *)&LAB_4018cedf_1)(_DAT_3ffbdea0,0xffffffff,0x400e79dc,0);
      if (iVar2 != 0) {
        uVar10 = func_0x40085c04();
        uVar3 = FUN_401847ec("02X%02X");
        uVar4 = (*(code *)&SUB_4000cff8)((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),1000,0);
        uVar9 = 0x24a;
        pcVar8 = "iled!\r\n";
        goto LAB_400e7cfa;
      }
      iVar2 = (*(code *)&LAB_4018cedf_1)(_DAT_3ffbde84,0xffffffff,0x400e79dc,0,0);
      if (iVar2 != 0) {
        uVar10 = func_0x40085c04();
        uVar3 = FUN_401847ec("02X%02X");
        uVar4 = (*(code *)&SUB_4000cff8)((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),1000,0);
        uVar9 = 0x24f;
        pcVar8 = "iled!\r\n";
        goto LAB_400e7cfa;
      }
      iVar2 = (*(code *)&LAB_4018cedf_1)(_DAT_3ffbde94,0xffffffff,0x400e79dc,0,0);
      if (iVar2 != 0) {
        uVar10 = func_0x40085c04();
        uVar3 = FUN_401847ec("02X%02X");
        uVar4 = (*(code *)&SUB_4000cff8)((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),1000,0);
        uVar9 = 0x254;
        pcVar8 = "iled!\r\n";
        goto LAB_400e7cfa;
      }
      iVar2 = (*(code *)&LAB_4018cedf_1)(_DAT_3ffbde80,0xffffffff,0x400e79dc,0,0);
      if (iVar2 != 0) {
        uVar10 = func_0x40085c04();
        uVar3 = FUN_401847ec("02X%02X");
        uVar4 = (*(code *)&SUB_4000cff8)((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),1000,0);
        uVar9 = 0x25a;
        pcVar8 = "iled!\r\n";
        goto LAB_400e7cfa;
      }
      iVar2 = (*(code *)&LAB_4018cedf_1)(_DAT_3ffbf670,0xffffffff,0x400e79dc,0,0);
      if (iVar2 != 0) {
        uVar10 = func_0x40085c04();
        uVar3 = FUN_401847ec("02X%02X");
        uVar4 = (*(code *)&SUB_4000cff8)((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),1000,0);
        uVar9 = 0x260;
        pcVar8 = "iled!\r\n";
        goto LAB_400e7cfa;
      }
      uVar1 = 1;
    }
    *(undefined1 *)puVar6 = uVar1;
  } while( true );
}

