// Function : FUN_400e7fec
// Address  : 0x400e7fec
// Size     : 367 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char FUN_400e7fec(uint param_1)

{
  char cVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  undefined8 uVar6;
  undefined4 uStack_190;
  undefined4 uStack_18c;
  undefined1 auStack_188 [108];
  undefined4 uStack_11c;
  undefined4 uStack_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined4 uStack_104;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  undefined4 uStack_ec;
  undefined4 uStack_e4;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 auStack_b4 [36];
  char *pcStack_24;
  
  cVar1 = DAT_3ffc517e;
  param_1 = param_1 & 0xff;
  pcVar5 = &DAT_3ffc517e;
  memw();
  memw();
  pcStack_24 = _DAT_3ffc5708;
  if (DAT_3ffc517e != '\0') goto LAB_400e8154;
  DAT_3ffc517e = '\x01';
  iVar3 = FUN_400e7c74();
  pcVar5 = &DAT_3ffc517e;
  cVar2 = '\0';
  if (iVar3 != 0) goto LAB_400e802c;
  while( true ) {
    DAT_3ffc517e = cVar1;
    pcVar5 = _DAT_3ffc5708;
    memw();
    memw();
    if (pcStack_24 == _DAT_3ffc5708) break;
    func_0x40082ecc();
LAB_400e802c:
    if (_DAT_3ffc51b0 == 0) {
      _DAT_3ffc51b0 = FUN_401071f4();
    }
    if (_DAT_3ffc51ac == 0) {
      _DAT_3ffc51ac = FUN_40107230();
    }
    func_0x4008b538(&uStack_114,0,0x5c);
    uStack_190 = 0x401019cc;
    uStack_e4 = 6;
    uStack_dc = 0x2f0;
    uStack_18c = 0x3ffbdef8;
    uStack_c4 = 7;
    uStack_11c = 8;
    uStack_110 = 8;
    uStack_104 = 5;
    uStack_c0 = 0x1f2f3f4f;
    uStack_100 = 0x10;
    uStack_118 = 0x20;
    uStack_fc = 1;
    uStack_f8 = 1;
    uStack_f4 = 1;
    uStack_ec = 1;
    uStack_d8 = 0x20;
    func_0x4008b3d8(auStack_188,"e %s\n",0x6c);
    uStack_cc = _DAT_3ffbde9c;
    uStack_d0 = _DAT_3ffbde98;
    if (DAT_3ffc517d == '\0') {
      uStack_114 = 1;
      uStack_10c = 0x20;
      uStack_100 = 4;
      uStack_11c = 4;
      uStack_110 = 0;
    }
    iVar3 = FUN_40106dd8(&uStack_190);
    if (iVar3 == 0) {
      if (param_1 == 0) {
        iVar3 = FUN_40147168(1);
        if (iVar3 == 0) {
          param_1 = 1;
        }
        *pcVar5 = (char)param_1;
      }
      if (*pcVar5 != '\0') {
        auStack_b4[0] = 0;
        FUN_400e7948(auStack_b4);
      }
LAB_400e8154:
      cVar2 = *pcVar5;
      cVar1 = DAT_3ffc517e;
    }
    else {
      uVar6 = func_0x40085c04();
      param_1 = FUN_401847ec("02X%02X");
      uVar4 = (*(code *)&SUB_4000cff8)((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),1000,0);
      FUN_4012105c("iled!\r\n",uVar4,param_1,0x2ad,"allback",iVar3);
      *pcVar5 = '\0';
      cVar1 = DAT_3ffc517e;
    }
  }
  return cVar2;
}

