// Function : FUN_400df4b4
// Address  : 0x400df4b4
// Size     : 71 bytes


void FUN_400df4b4(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  do {
    do {
      func_0x40091d60(0,1,500);
      memw();
    } while (*(char *)(param_1 + 0x7d) == '\0');
    memw();
    *(undefined1 *)(param_1 + 0x7d) = 0;
    memw();
    uVar1 = FUN_400df484(*(undefined4 *)(param_1 + 0x80));
    memw();
    uVar2 = FUN_400df484(*(undefined4 *)(param_1 + 0x84));
    FUN_400f06a4(0x3ffc5490,"ed",uVar1,uVar2);
  } while( true );
}

