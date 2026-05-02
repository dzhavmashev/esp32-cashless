// Function : FUN_4011e1b4
// Address  : 0x4011e1b4
// Size     : 472 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4011e1b4(uint *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  uint *puVar5;
  uint *puVar6;
  uint *puVar7;
  uint *puVar8;
  uint uVar9;
  uint *puVar10;
  uint *puVar11;
  uint *puVar12;
  uint *puVar13;
  undefined4 uVar14;
  char *pcVar15;
  uint uVar16;
  char *pcVar17;
  uint *in_t0;
  int in_WindowStart;
  undefined8 uVar18;
  undefined1 auStack_60 [16];
  uint *puStack_50;
  uint *puStack_4c;
  uint *puStack_48;
  uint *puStack_44;
  uint uStack_34;
  uint *puStack_30;
  uint uStack_2c;
  uint *puStack_28;
  uint *puStack_24;
  
  memw();
  memw();
  puStack_24 = _DAT_3ffc5708;
  puVar10 = (uint *)0x36e6f690;
  iVar1 = (uint)(in_WindowStart == 0) * (int)auStack_60;
  iVar3 = (uint)(in_WindowStart != 0) * (int)&stack0xc9190910;
  memw();
  puStack_48 = param_1;
  puStack_50 = (uint *)(*(code *)&SUB_4008b3d0)(iVar1 + iVar3 + 0x10,"",0x36e6f690);
  iVar2 = (uint)(in_WindowStart == 0) * (iVar1 + iVar3);
  iVar1 = (uint)(in_WindowStart != 0) * (iVar1 + iVar3 + -0x70);
  puVar7 = (uint *)(iVar2 + iVar1 + 0x10);
  memw();
  (*(code *)&SUB_4008b3d0)(puVar7);
  FUN_40187200(puVar7,0xd,8,0x401855e4);
  puVar13 = (uint *)0x0;
  uVar14 = 0xfffffffc;
  pcVar15 = &DAT_0000000c;
  puVar12 = (uint *)&DAT_0000000d;
  puVar8 = puVar7;
  puVar11 = puStack_50;
  do {
    puVar5 = puStack_24;
    uVar18 = CONCAT44(uVar14,puVar13);
    puVar6 = puVar12;
    if (puVar13 == puVar12) {
      puStack_4c = (uint *)((int)puVar11 + (int)puVar10);
      puVar7 = puStack_48;
      puVar10 = puStack_4c;
LAB_4011e239:
      puVar6 = _DAT_3ffc5708;
      if (puVar11 != puStack_4c) {
        uStack_34 = *puVar11;
        puStack_30 = (uint *)puVar11[1];
        pcVar17 = (char *)(uStack_34 + (int)puStack_30);
        uStack_2c = puVar11[2];
        puStack_28 = (uint *)puVar11[3];
        puStack_44 = (uint *)0x0;
        puVar13 = puStack_30;
        uVar9 = uStack_34;
        puVar6 = puVar8;
        while (puStack_44 != puVar12) {
          uVar16 = puVar6[1];
          if ((int)uVar9 < (int)uVar16) {
            pcVar15 = (char *)*puVar6;
            if ((int)pcVar17 <= (int)pcVar15) break;
            puVar10 = (uint *)(uint)((int)pcVar15 <= (int)uVar9);
            if ((int)pcVar17 <= (int)uVar16 && (int)pcVar15 <= (int)uVar9) goto LAB_4011e365;
            if (((int)uVar16 < (int)pcVar17) && ((int)uVar9 < (int)pcVar15)) {
              puVar13 = (uint *)(pcVar15 + -uVar9);
              puVar11[1] = (int)puStack_30 - (uVar16 - uStack_34);
              *puVar11 = uVar16;
              bVar4 = false;
              puVar10 = puVar13;
              if (0x10 < (int)puVar13) goto LAB_4011e34f;
              goto LAB_4011e239;
            }
            if ((int)uVar9 < (int)pcVar15) {
              puVar13 = (uint *)(pcVar15 + -uVar9);
              pcVar17 = pcVar15;
            }
            else {
              puVar13 = (uint *)(pcVar17 + -uVar16);
              uVar9 = uVar16;
            }
          }
          puVar6 = puVar6 + 2;
          puStack_44 = (uint *)((int)puStack_44 + 1);
          memw();
        }
        bVar4 = true;
        puVar10 = puVar13;
        if (&DAT_00000010 < puVar13) {
          memw();
LAB_4011e34f:
          puVar7[1] = (uint)puVar13;
          *puVar7 = uVar9;
          puVar7[2] = uStack_2c;
          puVar7[3] = (uint)puStack_28;
          puVar7 = puVar7 + 4;
          puVar10 = puStack_28;
          uStack_34 = uVar9;
          puStack_30 = puVar13;
          if (!bVar4) goto LAB_4011e239;
        }
LAB_4011e365:
        puVar11 = puVar11 + 4;
        memw();
        goto LAB_4011e239;
      }
      puVar7 = (uint *)((int)puVar7 - (int)puStack_48 >> 4);
      memw();
      memw();
      if (puStack_24 == _DAT_3ffc5708) {
        return;
      }
      memw();
      puVar11 = in_t0;
      uVar18 = (*(code *)&SUB_40082ec4)();
      puVar8 = puVar5;
      in_t0 = puVar11;
    }
    uVar16 = (uint)((ulonglong)uVar18 >> 0x20);
    uVar9 = puVar7[1] + 3 & uVar16;
    puVar12 = (uint *)(uVar16 & *puVar7);
    *puVar7 = (uint)puVar12;
    puVar7[1] = uVar9;
    if ((int)puVar12 <= (int)uVar9) goto LAB_4011e28d;
    uVar14 = 0x62;
    pcVar17 = "ap_free";
    puVar11 = in_t0;
    while( true ) {
      pcVar15 = "0x%08x\n";
      memw();
      uVar18 = (*(code *)&SUB_40094c54)("ap/port/memory_layout_utils.c",uVar14,"0x%08x\n",pcVar17);
      puVar12 = puVar11;
      in_t0 = puVar11;
LAB_4011e28d:
      puVar13 = puVar7 + 2;
      if (pcVar15 <= (char *)uVar18) goto LAB_4011e2de;
      if ((int)puVar12 < (int)puVar7[2]) break;
      uVar14 = 100;
      pcVar17 = "utils.c";
      puVar11 = in_t0;
    }
    if ((int)puVar7[2] < (int)uVar9) {
      puVar6 = (uint *)0x0;
      puVar11 = in_t0;
      if (_DAT_3ffbe0e8 != 0) {
        memw();
        puStack_50 = puVar13;
        uVar14 = (*(code *)&SUB_40094b80)();
        puVar6 = (uint *)puStack_50[1];
        *(uint **)(iVar2 + iVar1) = puVar6;
        puVar13 = (uint *)*puVar7;
        pcVar15 = "].start";
        memw();
        (*(code *)&SUB_40007d54)("_layout",uVar14,"].start",puVar13,puVar7[1],*puStack_50);
        puVar11 = in_t0;
      }
      uVar18 = (*(code *)&SUB_40094bc8)();
      in_t0 = puVar11;
    }
LAB_4011e2de:
    puVar7 = puVar13;
    uVar14 = (undefined4)((ulonglong)uVar18 >> 0x20);
    puVar13 = (uint *)((int)uVar18 + 1);
    puVar12 = puVar6;
  } while( true );
}

