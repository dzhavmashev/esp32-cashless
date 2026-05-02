// Function : FUN_4014bef8
// Address  : 0x4014bef8
// Size     : 60 bytes


undefined4 FUN_4014bef8(undefined1 *param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    FUN_40147fe4(1,0x800,1,"",&DAT_3f423a5e,0x8da);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  *param_1 = 0x3d;
  param_1[1] = 0x16;
  memw();
  memw();
  uVar1 = FUN_4014bdb4(param_1 + 2,param_2);
  return uVar1;
}

