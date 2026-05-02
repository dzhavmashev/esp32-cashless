// Function : FUN_40101bc4
// Address  : 0x40101bc4
// Size     : 290 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40101bc4(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,int param_6,uint param_7)

{
  int iVar1;
  uint uVar2;
  byte *pbVar3;
  uint uVar4;
  uint uVar5;
  undefined1 *puVar6;
  undefined1 *in_t0;
  undefined1 auStack_68 [2];
  undefined1 uStack_66;
  undefined1 uStack_65;
  undefined1 *puStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined1 *puStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined1 auStack_44 [32];
  uint uStack_24;
  
  puVar6 = auStack_68;
  memw();
  memw();
  uStack_24 = _DAT_3ffc5708;
  uVar5 = param_7 + 7 >> 3;
  uStack_54 = 2;
  memw();
  puStack_64 = puVar6;
  uStack_60 = param_3;
  uStack_50 = (*(code *)&SUB_4008c01c)(param_3);
  uStack_48 = 2;
  uStack_65 = (undefined1)(param_7 >> 8);
  uVar2 = 0;
  uVar4 = 1;
  uStack_66 = (undefined1)param_7;
  memw();
  uStack_5c = param_4;
  puStack_58 = &uStack_66;
  uStack_4c = param_5;
  do {
    if (uVar2 < uVar5) {
      puVar6[1] = (char)(uVar4 >> 8);
      *puVar6 = (char)uVar4;
      memw();
      if (uVar5 - uVar2 < 0x20) {
        memw();
        iVar1 = FUN_401020e4(param_1,param_2,4,&puStack_64,&uStack_54,auStack_44);
        if (iVar1 < 0) goto LAB_40101c5a;
        (*(code *)&SUB_4008b3d0)(param_6 + uVar2,auStack_44,uVar5 - uVar2);
        uVar2 = uVar5;
        goto LAB_40101cac;
      }
      memw();
      iVar1 = FUN_401020e4(param_1,param_2,4,&puStack_64,&uStack_54,param_6 + uVar2);
      if (iVar1 < 0) {
LAB_40101c5a:
        puVar6 = in_t0;
        param_1 = 0xffffffff;
        goto LAB_40101c5c;
      }
    }
    else {
LAB_40101cac:
      if ((param_7 & 7) != 0) {
        pbVar3 = (byte *)(param_6 + (uVar2 - 1));
        *pbVar3 = (byte)(0xff << 0x20 - (0x20 - (8 - (param_7 & 7) & 0x1f))) & *pbVar3;
        memw();
      }
      memw();
      FUN_40102884(auStack_44,0x20);
      param_1 = 0;
      puVar6 = in_t0;
LAB_40101c5c:
      uVar2 = uStack_24;
      param_2 = _DAT_3ffc5708;
      memw();
      memw();
      if (uStack_24 == _DAT_3ffc5708) {
        return;
      }
      (*(code *)&SUB_40082ec4)();
      in_t0 = puVar6;
    }
    uVar2 = uVar2 + 0x20;
    uVar4 = uVar4 + 1 & 0xffff;
  } while( true );
}

