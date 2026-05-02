// Function : FUN_400fe324
// Address  : 0x400fe324
// Size     : 89 bytes


void FUN_400fe324(int *param_1)

{
  uint uVar1;
  
  do {
    memw();
    memw();
    memw();
    memw();
    uVar1 = *(uint *)(*param_1 + 0x60);
    memw();
    if ((*(uint *)(*param_1 + 0x1c) & 0xff) == 0) {
      memw();
      memw();
      if ((uVar1 >> 2 & 0x7ff) == (uVar1 >> 0xd & 0x7ff)) {
        return;
      }
    }
    memw();
    memw();
  } while( true );
}

