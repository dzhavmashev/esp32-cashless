// Function : FUN_4015b1ec
// Address  : 0x4015b1ec
// Size     : 95 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4015b1ec(undefined1 *param_1)

{
  int iVar1;
  
  if (param_1 == (undefined1 *)0x0) {
    FUN_40147fe4(1,0x800,1,"type=%d","coexist",0x195);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  (**(code **)(_DAT_3ffc1a34 + 0x54))(_DAT_3ffc799c);
  iVar1 = _DAT_3ffbfdf0;
  DAT_3ffc8a04 = 1;
  memw();
  *(undefined1 *)(_DAT_3ffbfdf0 + 0x50) = *param_1;
  memw();
  *(undefined1 *)(iVar1 + 0x51) = param_1[1];
  memw();
  memw();
  (**(code **)(_DAT_3ffc1a34 + 0x58))(_DAT_3ffc799c);
  return;
}

