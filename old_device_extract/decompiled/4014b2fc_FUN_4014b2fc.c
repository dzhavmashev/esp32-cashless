// Function : FUN_4014b2fc
// Address  : 0x4014b2fc
// Size     : 72 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4014b2fc(undefined4 param_1)

{
  if (DAT_3ffc8a37 == '\0') {
    if (DAT_3ffc8a38 == '\0') {
      FUN_40147fe4(1,0x800,1,"",&DAT_3f423a5e,0x4bc);
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    (**(code **)(_DAT_3ffc1a34 + 0xf8))(0x3ffc8a3c,param_1);
    DAT_3ffc8a37 = '\x01';
    memw();
  }
  memw();
  return 0;
}

