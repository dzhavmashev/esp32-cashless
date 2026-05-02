// Function : FUN_40142b24
// Address  : 0x40142b24
// Size     : 747 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40142b24(int param_1,uint param_2,int param_3,uint param_4,int param_5,uint param_6,
                 undefined4 param_7,undefined1 param_8,uint param_9)

{
  uint uVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  byte bVar4;
  int iVar5;
  byte *pbVar6;
  uint uVar7;
  undefined1 *puVar8;
  uint uVar9;
  undefined1 *puStack_28c;
  uint uStack_288;
  int iStack_284;
  uint uStack_280;
  uint uStack_27c;
  int iStack_278;
  undefined1 auStack_270 [12];
  undefined1 auStack_264 [64];
  undefined1 auStack_224 [127];
  byte abStack_1a5 [128];
  char acStack_125 [128];
  byte abStack_a5 [129];
  uint uStack_24;
  
  memw();
  memw();
  uStack_24 = _DAT_3ffc5708;
  uVar1 = (uint)(0x40 < param_4 || 0x40 < param_6);
  uStack_288 = param_2;
  iStack_278 = param_1;
  if ((0x40 < param_4 || 0x40 < param_6) || (0x80 < param_2)) {
    puStack_28c = &DAT_ffffe080;
    memw();
  }
  else {
    uVar9 = uVar1;
    if (param_4 != 0) {
      uVar9 = 1;
    }
    if (param_3 == 0) {
      uVar1 = 1;
    }
    if (((uVar1 == 0) || (puStack_28c = &DAT_ffffe080, uVar9 == 0)) &&
       ((param_5 != 0 || (puStack_28c = &DAT_ffffe080, param_6 == 0)))) {
      memw();
      iStack_284 = FUN_40138f28(param_7);
      puStack_28c = (undefined1 *)0xffffe100;
      if (iStack_284 != 0) {
        memw();
        FUN_40138f64(auStack_270);
        puStack_28c = (undefined1 *)FUN_4013905c(auStack_270,iStack_284,0);
        if (puStack_28c == (undefined1 *)0x0) {
          memw();
          uStack_280 = FUN_401864c4(iStack_284);
          puVar2 = (undefined1 *)0x40;
          if (0x20 < uStack_280) {
            puVar2 = (undefined1 *)0x80;
          }
          uStack_27c = (uint)(param_6 != 0 && param_5 != 0);
          memw();
          (*(code *)&SUB_4008b530)(auStack_224,param_8,puVar2);
          if (uStack_27c != 0) {
            FUN_40142af8(abStack_1a5 + 1,puVar2,param_5,param_6);
          }
          uVar9 = uVar9 & param_3 != 0;
          if (uVar9 == 0) goto LAB_40142c32;
          FUN_40142af8(acStack_125 + 1,puVar2,param_3,param_4);
          goto LAB_40142c32;
        }
      }
    }
  }
  do {
    uVar9 = _DAT_3ffc5708;
    memw();
    memw();
    if (uStack_24 == _DAT_3ffc5708) {
      return;
    }
    memw();
    (*(code *)&SUB_40082ec4)();
    puVar2 = puStack_28c;
    while (puVar3 = (undefined1 *)FUN_40139174(auStack_270,acStack_125 + 1,puVar2),
          puVar3 == (undefined1 *)0x0) {
      do {
        puVar3 = (undefined1 *)FUN_401391c4(auStack_270,auStack_264);
        if (puVar3 != (undefined1 *)0x0) goto LAB_40142cbd;
        for (uVar1 = 1; uVar1 < param_9; uVar1 = uVar1 + 1) {
          puVar3 = (undefined1 *)FUN_40139210(iStack_284,auStack_264,uStack_280,auStack_264);
          if (puVar3 != (undefined1 *)0x0) goto LAB_40142cbd;
        }
        iVar5 = (uStack_288 < uStack_280) * uStack_288 + (uStack_288 >= uStack_280) * uStack_280;
        (*(code *)&SUB_4008b3d0)(iStack_278,auStack_264,iVar5);
        uStack_288 = uStack_288 - iVar5;
        iStack_278 = iStack_278 + iVar5;
        if (uStack_288 == 0) {
LAB_40142c9d:
          memw();
          puVar3 = puStack_28c;
          goto LAB_40142cbd;
        }
        pbVar6 = abStack_a5 + 1;
        FUN_40142af8(pbVar6,puVar2,auStack_264,uStack_280);
        puVar3 = puVar2;
        do {
          puVar3 = puVar3 + -1;
          bVar4 = pbVar6[(int)puVar3] + 1;
          pbVar6[(int)puVar3] = bVar4;
          memw();
        } while (puVar3 != (undefined1 *)0x0 && bVar4 == 0);
        if (uStack_27c != 0) {
          uVar1 = 0;
          puVar3 = puVar2;
          puVar8 = puVar2;
          do {
            uVar7 = (uint)abStack_a5[(int)puVar3] + (uint)abStack_1a5[(int)puVar3] + uVar1;
            uVar1 = uVar7 >> 8;
            abStack_1a5[(int)puVar3] = (byte)uVar7;
            memw();
            puVar8 = puVar8 + -1;
            puVar3 = puVar3 + -1;
          } while (puVar8 != (undefined1 *)0x0);
        }
        if (uVar9 != 0) {
          acStack_125[(int)puVar2] = abStack_a5[(int)puVar2] + acStack_125[(int)puVar2];
          memw();
          memw();
        }
LAB_40142c32:
        if (uStack_288 == 0) goto LAB_40142c9d;
        puVar3 = (undefined1 *)FUN_40139114(auStack_270);
        if (((puVar3 != (undefined1 *)0x0) ||
            (puVar3 = (undefined1 *)FUN_40139174(auStack_270,auStack_224,puVar2),
            puVar3 != (undefined1 *)0x0)) ||
           ((uStack_27c != 0 &&
            (puVar3 = (undefined1 *)FUN_40139174(auStack_270,abStack_1a5 + 1,puVar2),
            puVar3 != (undefined1 *)0x0)))) goto LAB_40142cbd;
      } while (uVar9 == 0);
    }
LAB_40142cbd:
    FUN_4013ae54(abStack_1a5 + 1,0x80);
    FUN_4013ae54(acStack_125 + 1,0x80);
    FUN_4013ae54(abStack_a5 + 1,0x80);
    FUN_4013ae54(auStack_264,0x40);
    FUN_40138f78(auStack_270);
    puStack_28c = puVar3;
  } while( true );
}

