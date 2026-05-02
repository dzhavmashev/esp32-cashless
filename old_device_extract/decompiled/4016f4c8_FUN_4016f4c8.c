// Function : FUN_4016f4c8
// Address  : 0x4016f4c8
// Size     : 156 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4016f4c8(void)

{
  uint uVar1;
  undefined1 auStack_80 [13];
  undefined1 auStack_73 [13];
  undefined1 local_66 [13];
  undefined1 auStack_59 [13];
  undefined1 auStack_4c [13];
  undefined1 auStack_3f [13];
  undefined1 auStack_32 [50];
  
  if ((_DAT_3ffca4c8 & 0x10) == 0) {
    FUN_4016e6ac();
  }
  if ((_DAT_3ffca4c8 & 0x2000) == 0) {
    FUN_4016ef10(auStack_32,auStack_3f,auStack_4c,&DAT_3ffca674,local_66,auStack_59,auStack_73,0xd,
                 auStack_80);
    FUN_4016e840(auStack_32,auStack_3f,auStack_4c,&DAT_3ffca674,local_66,auStack_59,auStack_73,0xd,
                 auStack_80);
    DAT_3ffca660 = local_66[0];
    memw();
    FUN_4016f3ec(0xc);
    uVar1 = (*(code *)&SUB_40084594)(&DAT_60033d38);
    _DAT_60033d38 = uVar1 & 0xffff | 0xc800000;
    _DAT_3ffca4c8 = _DAT_3ffca4c8 | 0x2000;
    memw();
  }
  FUN_4016b0bc();
  return;
}

