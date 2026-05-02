// Function : FUN_4014bf3c
// Address  : 0x4014bf3c
// Size     : 82 bytes


undefined4 FUN_4014bf3c(undefined1 *param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    FUN_40147fe4(1,0x800,1,"",&DAT_3f423a5e,0x8e7);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  *param_1 = 0xdd;
  param_1[1] = 0x1a;
  param_1[2] = 0;
  param_1[3] = 0x90;
  param_1[4] = 0x4c;
  param_1[5] = 0x34;
  memw();
  memw();
  uVar1 = FUN_4014bdb4(param_1 + 6,param_2);
  return uVar1;
}

