// Function : FUN_40121320
// Address  : 0x40121320
// Size     : 375 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40121320(undefined4 *param_1,undefined4 param_2,uint param_3,code *param_4)

{
  bool bVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  undefined1 *puVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  int aiStack_24 [9];
  
  aiStack_24[0] = 0;
  memw();
  uVar4 = FUN_40185644(param_1);
  puVar2 = _DAT_3ffc6d38;
  if (param_3 != 0) {
    uVar4 = (uVar4 < param_3) * uVar4 + (uVar4 >= param_3) * param_3;
  }
  memw();
  puVar5 = (undefined1 *)0x0;
  do {
    if (((puVar5 != (undefined1 *)0x0) || ((int)uVar4 <= aiStack_24[0])) ||
       (puVar5 = (undefined1 *)*param_1, puVar5 == (undefined1 *)0x0)) {
      memw();
      param_1 = (undefined4 *)&DAT_3ffc6d38;
      if (puVar5 == (undefined1 *)0x0) {
        if (param_4 != (code *)0x401215c0) {
          param_4 = (code *)(uint)(param_4 == (code *)0x401214f4);
          param_1 = (undefined4 *)0x401214f4;
          if (param_4 == (code *)0x0) goto LAB_4012138c;
        }
        param_1 = puVar2;
        if ((puVar2 != _DAT_3ffc6d38) || (((uint)puVar2 & 1) != 0)) {
          puVar5 = (undefined1 *)0x1606;
        }
      }
LAB_4012138c:
      if (aiStack_24[0] <= (int)uVar4) {
        return;
      }
      memw();
      (*(code *)&SUB_40094c54)("use/src/esp_efuse_utility.c",0x58,"ead_reg","scheme\n");
    }
    uVar7 = (uint)(byte)puVar5[1] + (uint)*(ushort *)(puVar5 + 2);
    if (((uVar7 < 0x101) && ((iVar8 = FUN_40121634(*puVar5), iVar8 != 1 || (uVar7 < 0xc1)))) &&
       ((iVar8 != 2 || (uVar7 < 0x81)))) {
      puVar5 = (undefined1 *)0x0;
    }
    else {
      if (_DAT_3ffbe0e8 != 0) {
        uVar6 = (*(code *)&SUB_40094b80)();
        (*(code *)&SUB_40007d54)(")",uVar6,"13FFC))");
      }
      puVar5 = (undefined1 *)0x1604;
    }
    iVar8 = 0;
    while( true ) {
      if ((puVar5 != (undefined1 *)0x0) || ((int)uVar4 <= aiStack_24[0])) goto LAB_40121498;
      puVar5 = (undefined1 *)*param_1;
      uVar7 = (uint)(byte)puVar5[1];
      iVar10 = ((int)uVar7 >> 5) + iVar8;
      uVar14 = (*(ushort *)(puVar5 + 2) + uVar7) - 1;
      uVar12 = *(ushort *)(puVar5 + 2) + uVar7 + 0x1e;
      if (-1 < (int)uVar14) {
        uVar12 = uVar14;
      }
      if ((int)uVar12 >> 5 < iVar10) break;
      uVar12 = uVar7 & 0x1f;
      if (iVar8 != 0) {
        uVar12 = 0;
      }
      memw();
      iVar11 = 0;
      iVar3 = 0;
      while (iVar13 = iVar3, (int)uVar7 <= (int)uVar14) {
        uVar9 = uVar7 + 1;
        if (((uVar9 & 0x1f) == 0) ||
           (bVar1 = uVar7 == uVar14, uVar7 = uVar9, iVar3 = iVar13 + 1, bVar1)) {
          iVar13 = iVar13 + 1;
          if (iVar8 == iVar11) {
            if ((int)uVar4 < aiStack_24[0] + iVar13) {
              iVar13 = uVar4 - aiStack_24[0];
            }
            goto LAB_40121475;
          }
          uVar7 = uVar9;
          iVar11 = iVar11 + 1;
          iVar3 = 0;
        }
      }
      iVar13 = 0;
LAB_40121475:
      iVar8 = iVar8 + 1;
      puVar5 = (undefined1 *)(*param_4)(iVar10,*puVar5,uVar12,iVar13,param_2,aiStack_24);
    }
    puVar5 = (undefined1 *)0x0;
LAB_40121498:
    param_1 = param_1 + 1;
  } while( true );
}

