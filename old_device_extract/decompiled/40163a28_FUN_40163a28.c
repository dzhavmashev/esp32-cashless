// Function : FUN_40163a28
// Address  : 0x40163a28
// Size     : 134 bytes


void FUN_40163a28(int param_1,int param_2,short param_3)

{
  *(short *)(param_1 + 0x16) = param_3 - *(short *)(param_1 + 0x14);
  memw();
  *(undefined1 *)(*(int *)(param_1 + 0x2c) + 5) = 0;
  memw();
  *(undefined1 *)(*(int *)(param_1 + 0x2c) + 6) = 0;
  memw();
  *(undefined1 *)(*(int *)(param_1 + 0x2c) + 7) = 0;
  memw();
  **(uint **)(param_1 + 0x2c) = **(uint **)(param_1 + 0x2c) | 0x480000;
  if (0xf < (byte)(*(char *)(*(int *)(param_1 + 0x2c) + 0xc) - 0x10U)) {
    memw();
    FUN_40147fe4(6,0x800,1,&DAT_3f4010e7,"s_func_app.c",0x999);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  FUN_40188920(param_1);
  memw();
  memw();
  **(uint **)(param_2 + 8) = **(uint **)(param_2 + 8) | 0x40000000;
  *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x18) =
       *(undefined4 *)(*(int *)(param_2 + 0x2c) + 0x18);
  memw();
  return;
}

