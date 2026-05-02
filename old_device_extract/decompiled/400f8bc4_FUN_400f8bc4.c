// Function : FUN_400f8bc4
// Address  : 0x400f8bc4
// Size     : 493 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_400f8bc4(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  int iStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined1 auStack_90 [20];
  undefined1 auStack_7c [88];
  undefined4 *puStack_24;
  
  memw();
  memw();
  puStack_24 = _DAT_3ffc5708;
  memw();
  (*(code *)&SUB_40086460)(0x3ffc55a4);
  puVar5 = _DAT_3ffc55a8;
  if (_DAT_3ffc55a8 == (undefined4 *)0x0) goto LAB_400f8c10;
LAB_400f8bea:
  iVar1 = 0;
  do {
    (*(code *)&SUB_400864a0)(0x3ffc55a4);
    puVar5 = _DAT_3ffc5708;
    memw();
    memw();
    if (puStack_24 == _DAT_3ffc5708) {
      return iVar1;
    }
    (*(code *)&SUB_40082ec4)();
LAB_400f8c10:
    (*(code *)&SUB_4005da7c)(auStack_7c);
    iVar1 = (*(code *)&SUB_40081e08)(puVar5,0x1000,puVar5,&iStack_a4,&uStack_a0);
    if (iVar1 == 0) {
      iVar1 = iStack_a4 + 0x8000;
      iVar7 = iStack_a4 + 0x9000;
      puVar6 = puVar5;
      iStack_a4 = iVar1;
      while (iVar1 != iVar7) {
        (*(code *)&SUB_4008b3d0)(&uStack_9c,iVar1,0x20);
        if ((uStack_9c & 0xffff) == 0xebeb) {
          (*(code *)&SUB_4005db1c)(&uStack_9c,auStack_7c);
          iVar1 = (*(code *)&SUB_4008b33c)(&uStack_9c,iVar1 + 0x10);
          if (iVar1 != 0) {
            uVar2 = (*(code *)&SUB_40094b80)();
            FUN_4012113c(1," update partition"," table\n",uVar2," update partition");
            iVar1 = 0x103;
            goto LAB_400f8c68;
          }
          iVar1 = 0;
          _DAT_3ffc55a8 = puVar5;
          goto LAB_400f8d4c;
        }
        if ((uStack_9c & 0xffff) != 0x50aa) break;
        (*(code *)&SUB_4005da9c)(auStack_7c,&uStack_9c,0x20);
        puVar3 = (undefined4 *)(*(code *)&SUB_40094dd8)(0x30,1);
        if (puVar3 == (undefined4 *)0x0) break;
        *puVar3 = _DAT_3ffc56b8;
        puVar3[3] = uStack_98;
        puVar3[4] = uStack_94;
        puVar3[1] = uStack_9c >> 0x10 & 0xff;
        puVar3[2] = uStack_9c >> 0x18;
        *(byte *)((int)puVar3 + 0x25) = (byte)auStack_90._16_4_ & 1;
        *(undefined1 *)(puVar3 + 10) = 0;
        memw();
        memw();
        iVar4 = (*(code *)&SUB_40083c80)();
        if (iVar4 == 0) {
          *(undefined1 *)((int)puVar3 + 0x25) = 0;
          memw();
        }
        else if ((uStack_9c._2_1_ == '\0') || ((uStack_9c & 0xfbff0000) == 0x10000)) {
          *(undefined1 *)((int)puVar3 + 0x25) = 1;
          memw();
          memw();
        }
        memw();
        (*(code *)&SUB_4008c0f8)(puVar3 + 5,auStack_90,0x10);
        if (puVar6 == (undefined4 *)0x0) {
          puVar3[0xb] = puVar5;
          puVar5 = puVar3;
        }
        else {
          puVar3[0xb] = puVar6[0xb];
          puVar6[0xb] = puVar3;
          memw();
        }
        iVar1 = iVar1 + 0x20;
        memw();
        puVar6 = puVar3;
      }
      memw();
      uVar2 = (*(code *)&SUB_40094b80)();
      FUN_4012113c(1," update partition","56_data",uVar2," update partition");
      iVar1 = 0x105;
LAB_400f8c68:
      while (puVar5 != (undefined4 *)0x0) {
        puVar6 = (undefined4 *)puVar5[0xb];
        (*(code *)&SUB_40094d80)(puVar5);
        puVar5 = puVar6;
      }
LAB_400f8d4c:
      memw();
      (*(code *)&SUB_40081e78)(uStack_a0);
      if (iVar1 == 0) goto LAB_400f8bea;
    }
    uVar2 = (*(code *)&SUB_40094b80)();
    FUN_4012113c(1," update partition","smatch\n",uVar2," update partition",iVar1);
  } while( true );
}

