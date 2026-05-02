// Function : FUN_400fdb2c
// Address  : 0x400fdb2c
// Size     : 80 bytes


void FUN_400fdb2c(void)

{
  int iVar1;
  uint uVar2;
  undefined1 in_PRID;
  
  iVar1 = (*(code *)&SUB_40083730)();
  if (iVar1 == -1) {
    (*(code *)&SUB_400835bc)();
  }
  (*(code *)&SUB_40082e64)();
  FUN_400fe71c();
  uVar2 = rsr(in_PRID);
  (*(code *)&SUB_40084224)((uVar2 >> 0xd & 1) == 0);
  (*(code *)&SUB_4008356c)(9);
  (*(code *)&SUB_40007d54)(&DAT_3f40dc4c);
  (*(code *)&SUB_400835bc)();
  do {
    ill();
  } while( true );
}

