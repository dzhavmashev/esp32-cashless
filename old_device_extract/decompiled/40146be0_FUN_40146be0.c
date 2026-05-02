// Function : FUN_40146be0
// Address  : 0x40146be0
// Size     : 321 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_40146be0(int param_1,char param_2)

{
  int iVar1;
  undefined1 *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  code *pcVar7;
  
  iVar1 = FUN_401460c8();
  if (iVar1 == 0) {
    return 0x3001;
  }
  if (DAT_3ffc89d9 < 2) {
    return 0x3002;
  }
  (**(code **)(_DAT_3ffc1a34 + 0x54))(_DAT_3ffc799c);
  uVar6 = (uint)DAT_3ffc7904;
  if ((uVar6 + 1 & 0xff) == 0x80) {
    DAT_3ffc7904 = 0;
    memw();
  }
  else {
    DAT_3ffc7904 = (byte)(uVar6 + 1);
    memw();
    memw();
  }
  memw();
  (**(code **)(_DAT_3ffc1a34 + 0x58))(_DAT_3ffc799c);
  FUN_40156a04(uVar6);
  if (param_1 == 0) {
    puVar2 = (undefined1 *)(**(code **)(_DAT_3ffc1a34 + 0x178))(0x18);
    if (puVar2 == (undefined1 *)0x0) {
      return 0x101;
    }
    *puVar2 = 5;
    memw();
    *(undefined **)(puVar2 + 4) = &DAT_4014f624;
    puVar2[8] = 1;
    puVar2[9] = 0;
    puVar2[10] = 0;
    memw();
    *(undefined4 *)(puVar2 + 0xc) = 0;
    *(undefined4 *)(puVar2 + 0x14) = 0;
  }
  else {
    puVar2 = (undefined1 *)(**(code **)(_DAT_3ffc1a34 + 0x178))(0x38);
    if (puVar2 == (undefined1 *)0x0) {
      return 0x101;
    }
    *puVar2 = 5;
    memw();
    *(undefined **)(puVar2 + 4) = &DAT_4014f624;
    puVar2[8] = 0;
    puVar2[9] = 0;
    puVar2[10] = 0;
    memw();
    *(undefined4 *)(puVar2 + 0xc) = 0;
    memw();
    (*(code *)&SUB_4008b3d0)(puVar2 + 0x14,param_1,0x20);
  }
  memw();
  iVar1 = FUN_40150444(puVar2);
  if (iVar1 == 0) {
    if (param_2 == '\0') {
LAB_40146cc6:
      iVar1 = 0;
    }
    else {
      uVar3 = FUN_40146b04(param_1);
      uVar5 = 0;
      do {
        uVar4 = FUN_40156a48();
        if ((uVar4 & 0x80) != 0) goto LAB_40146cc6;
        if (uVar6 != uVar4) {
          FUN_40147fe4(1,10,2,0x3f436367);
          return -1;
        }
        uVar5 = uVar5 + 1 & 0xff;
        pcVar7 = *(code **)(_DAT_3ffc1a34 + 0x9c);
        (**(code **)(_DAT_3ffc1a34 + 0xa0))(100);
        (*pcVar7)();
      } while (uVar3 != uVar5);
      FUN_40147fe4(1,10,5,0x3f435c2c);
      iVar1 = 0x300c;
    }
  }
  return iVar1;
}

