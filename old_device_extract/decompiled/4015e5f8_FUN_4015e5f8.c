// Function : FUN_4015e5f8
// Address  : 0x4015e5f8
// Size     : 198 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4015e5f8(void)

{
  int iVar1;
  code *pcVar2;
  
  iVar1 = FUN_4015be2c();
  if (iVar1 == 0) {
    FUN_40147fe4(1,8,4,0x3f4342dd);
  }
  else {
    iVar1 = *(int *)(_DAT_3ffc8800 + 0xe4);
    pcVar2 = *(code **)(_DAT_3ffc1a34 + 0xf4);
    *(undefined4 *)(iVar1 + 0x2e0) = 0;
    *(undefined4 *)(iVar1 + 0x2e4) = 0;
    memw();
    (*pcVar2)(iVar1 + 0x2cc,&DAT_4015bf04);
    if ((*(uint *)(iVar1 + 0x2c0) & 0xff) == 0 && *(uint *)(iVar1 + 700) >> 0x18 == 0) {
      *(undefined1 *)(iVar1 + 0x2bf) = 0x78;
      *(char *)(iVar1 + 0x2c0) = (char)(*(uint *)(iVar1 + 700) >> 0x18);
      memw();
      memw();
      FUN_40147fe4(1,8,4,0x3f434303);
    }
    FUN_40147fe4(1,1,3,0x3f435477,
                 (*(uint *)(iVar1 + 0x2c0) & 0xff) << 8 | *(uint *)(iVar1 + 700) >> 0x18);
    (**(code **)(_DAT_3ffc1a34 + 0xe8))
              (iVar1 + 0x2cc,
               ((*(uint *)(iVar1 + 0x2c0) & 0xff) << 8 | *(uint *)(iVar1 + 700) >> 0x18) * 1000,0);
  }
  return 0;
}

