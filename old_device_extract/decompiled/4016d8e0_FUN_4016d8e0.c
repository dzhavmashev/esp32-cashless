// Function : FUN_4016d8e0
// Address  : 0x4016d8e0
// Size     : 371 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4016d8e0(char param_1,char param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  char cVar4;
  uint uVar5;
  undefined2 uVar6;
  undefined1 auStack_40 [6];
  char acStack_3a [10];
  uint uStack_30;
  uint uStack_2c;
  int iStack_28;
  int iStack_24;
  
  FUN_4016f7a8((int)param_1,DAT_3ffca5b9,0);
  (**(code **)(_DAT_3ffc7e64 + 0x16c))(0x3ffca508,param_1);
  if (param_1 != '\x06') {
    if (param_2 == '\x01') goto LAB_4016d915;
    goto LAB_4016d965;
  }
  FUN_4016d800();
  if (param_2 == '\x01') {
LAB_4016d915:
    iVar1 = FUN_4016d5e4(&DAT_3ffca522,acStack_3a);
    if ((iVar1 == 0) && (acStack_3a[0] == '\x01')) {
LAB_4016d965:
      uStack_30 = 0;
      uVar3 = 0;
      uVar6 = 0;
    }
    else {
      iVar2 = FUN_4016d5e4(&DAT_3ffca522,acStack_3a);
      if ((iVar2 == 0) && (acStack_3a[0] == '\x01')) goto LAB_4016d965;
      uVar3 = ((short)((short)iVar1 + (short)iVar2) + 1) / 2;
      uStack_30 = uVar3 & 0xff;
      uVar6 = (undefined2)uVar3;
    }
    cVar4 = (char)uStack_30;
    uVar5 = (uint)(byte)(param_1 - 1);
    (**(code **)(_DAT_3ffc7e64 + 0x18c))(auStack_40,&DAT_3ffca522,uVar3);
    if (10 < uVar5) {
      uStack_2c = 0xffffff;
      iStack_24 = 0x17;
      iStack_28 = 0x12;
      uVar3 = 0x18;
      uVar5 = 3;
      goto LAB_4016d9bb;
    }
  }
  else {
    uVar5 = 5;
    cVar4 = '\0';
    (**(code **)(_DAT_3ffc7e64 + 0x18c))(auStack_40,&DAT_3ffca522,0);
    uVar6 = 0;
    uStack_30 = 0;
  }
  uVar5 = (uint)*(byte *)(uVar5 + 0x3ffc3a58);
  uVar3 = uVar5 << 3;
  iStack_28 = uVar5 * 6;
  uStack_2c = 0xff << 0x20 - (0x20 - (uVar3 & 0x1f)) ^ 0xffffffff;
  iStack_24 = iStack_28 + 5;
LAB_4016d9bb:
  *(undefined2 *)(&DAT_3ffca4cc + uVar5 * 2) = uVar6;
  uVar5 = (*(code *)&SUB_40084594)(&DAT_3ff460f8);
  _DAT_3ff460f8 = uVar5 & uStack_2c | uStack_30 << 0x20 - (0x20 - (uVar3 & 0x1f));
  memw();
  DAT_3ffc075e = cVar4 + DAT_3ffc075e;
  memw();
  FUN_4016d398(0x80,auStack_40,6,0x2b,iStack_28 + 0x3ffca528,_DAT_3ffca42c,(int)DAT_3ffc075e,0);
  DAT_3ffc075e = *(char *)(iStack_24 + 0x3ffca528) + '+';
  memw();
  return;
}

