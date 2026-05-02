// Function : FUN_40105538
// Address  : 0x40105538
// Size     : 731 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40105538(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4,int param_5,
                 int param_6,uint param_7)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  undefined4 uStack_25c;
  undefined1 auStack_258 [20];
  byte local_244 [20];
  undefined1 auStack_230 [40];
  undefined4 uStack_208;
  byte local_204 [8];
  uint uStack_1fc;
  uint uStack_1f8;
  uint uStack_1f4;
  uint uStack_1f0;
  uint uStack_1ec;
  undefined1 auStack_1a4 [8];
  undefined4 uStack_19c;
  undefined4 uStack_198;
  undefined4 uStack_194;
  undefined4 uStack_190;
  undefined4 uStack_18c;
  undefined4 uStack_148;
  undefined1 auStack_144 [8];
  uint uStack_13c;
  uint uStack_138;
  uint uStack_134;
  uint uStack_130;
  uint uStack_12c;
  undefined4 uStack_e8;
  byte local_e4 [8];
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined1 auStack_84 [8];
  uint uStack_7c;
  uint uStack_78;
  uint uStack_74;
  uint uStack_70;
  uint uStack_6c;
  uint uStack_24;
  
  memw();
  memw();
  uStack_24 = _DAT_3ffc5708;
  pcVar6 = "_ie_rsn";
  if (param_5 == 0) {
LAB_4010555c:
    memw();
    (*(code *)&SUB_40094c54)("/crypto/fastpbkdf2.c",0x182,"&& nout",pcVar6);
  }
  else if ((param_6 == 0) || (param_7 == 0)) {
    pcVar6 = "bkdf2.c";
    goto LAB_4010555c;
  }
  if (param_2 < 0x41) {
    (*(code *)&SUB_4008b3d0)(local_244,param_1,param_2);
    if (param_2 == 0x40) goto LAB_401055c2;
  }
  else {
    FUN_4013ec3c(auStack_1a4);
    FUN_4013eca8(auStack_1a4);
    uStack_148 = 2;
    memw();
    FUN_4013ecf4(auStack_1a4,param_1,param_2);
    FUN_4013ed0c(auStack_1a4,local_244);
    param_2 = 0x14;
  }
  (*(code *)&SUB_4008b530)(local_244 + param_2,0,0x40 - param_2);
LAB_401055c2:
  local_204[0] = local_244[0] ^ 0x36;
  local_e4[0] = local_244[0] ^ 0x5c;
  memw();
  memw();
  FUN_4013ec3c(auStack_1a4);
  FUN_4013eca8(auStack_1a4);
  uStack_148 = 2;
  memw();
  FUN_4013ecf4(auStack_1a4,local_204,0x40);
  FUN_4013ec3c(auStack_144);
  FUN_4013eca8(auStack_144);
  uStack_e8 = 2;
  memw();
  FUN_4013ecf4(auStack_144,local_e4,0x40);
  uVar3 = 1;
  uVar4 = param_7;
  do {
    uVar2 = uStack_24;
    uVar1 = _DAT_3ffc5708;
    if ((param_7 + 0x13) / 0x14 < uVar3) {
      memw();
      memw();
      if (uStack_24 == _DAT_3ffc5708) {
        return;
      }
      memw();
      (*(code *)&SUB_40082ec4)();
      uVar3 = uVar1;
      uVar4 = uVar2;
    }
    uStack_25c = (*(code *)&SUB_40064ae0)(uVar3);
    memw();
    (*(code *)&SUB_4008b530)(auStack_230,0,0x28);
    auStack_230[0] = 0x80;
    memw();
    uStack_208 = 0xa0020000;
    memw();
    (*(code *)&SUB_4008b3d0)(local_e4,auStack_1a4,0xc0);
    FUN_4013ecf4(local_e4,param_3,param_4);
    FUN_4013ecf4(local_e4,&uStack_25c,4);
    FUN_4013ed0c(local_e4,local_244);
    FUN_4013ecf4(auStack_84,local_244,0x14);
    FUN_4013ed0c(auStack_84,local_244);
    (*(code *)&SUB_4008b3d0)(local_204,auStack_84,0x60);
    iVar5 = 1;
    while (param_5 != iVar5) {
      uStack_dc = uStack_19c;
      uStack_d8 = uStack_198;
      uStack_d4 = uStack_194;
      uStack_d0 = uStack_190;
      uStack_cc = uStack_18c;
      memw();
      FUN_4013ece4(local_e4,local_244);
      FUN_401054f0(local_e4,local_244);
      uStack_7c = uStack_13c;
      uStack_78 = uStack_138;
      uStack_74 = uStack_134;
      uStack_70 = uStack_130;
      uStack_6c = uStack_12c;
      memw();
      FUN_4013ece4(auStack_84,local_244);
      FUN_401054f0(auStack_84,local_244);
      uStack_1fc = uStack_1fc ^ uStack_7c;
      uStack_1f8 = uStack_1f8 ^ uStack_78;
      uStack_1f4 = uStack_1f4 ^ uStack_74;
      uStack_1f0 = uStack_1f0 ^ uStack_70;
      uStack_1ec = uStack_1ec ^ uStack_6c;
      iVar5 = iVar5 + 1;
      memw();
    }
    FUN_401054f0(local_204,auStack_258);
    (*(code *)&SUB_4008b3d0)
              ((param_6 + param_7) - uVar4,auStack_258,
               (uVar4 < 0x14) * uVar4 + (uint)(uVar4 >= 0x14) * 0x14);
    uVar3 = uVar3 + 1;
    uVar4 = uVar4 - 0x14;
  } while( true );
}

