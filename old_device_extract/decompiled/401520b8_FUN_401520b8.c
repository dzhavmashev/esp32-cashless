// Function : FUN_401520b8
// Address  : 0x401520b8
// Size     : 132 bytes


int FUN_401520b8(int param_1)

{
  (*(code *)&SUB_4008b3d0)(param_1,&DAT_3f423e22,9);
  *(undefined1 *)(param_1 + 8) = 4;
  memw();
  *(undefined1 *)(param_1 + 9) = 0;
  memw();
  *(undefined1 *)(param_1 + 10) = 0;
  memw();
  *(undefined1 *)(param_1 + 0xb) = 0x22;
  memw();
  *(undefined1 *)(param_1 + 0xc) = 0;
  *(undefined1 *)(param_1 + 0xd) = 0;
  memw();
  memw();
  return param_1 + 0x1a;
}

