// Function : FUN_4014bd38
// Address  : 0x4014bd38
// Size     : 60 bytes


undefined4 FUN_4014bd38(undefined1 *param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    FUN_40147fe4(1,0x800,1,"",&DAT_3f423a5e,0x87b);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  *param_1 = 0x2d;
  param_1[1] = 0x1a;
  memw();
  memw();
  uVar1 = FUN_4014a350(param_1 + 2,param_2);
  return uVar1;
}

