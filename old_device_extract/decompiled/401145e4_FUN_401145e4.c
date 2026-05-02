// Function : FUN_401145e4
// Address  : 0x401145e4
// Size     : 87 bytes


uint FUN_401145e4(int param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  uVar2 = param_2 + 0xf0;
  uVar1 = FUN_401142d4(param_3,uVar2,0x3d,7);
  if (uVar1 < 0x80) goto LAB_40114600;
  do {
    uVar1 = FUN_40114310();
LAB_40114600:
    *(undefined1 *)(uVar2 + uVar1) = 1;
    memw();
    uVar1 = uVar1 + 1 & 0xffff;
    uVar2 = 0;
    while( true ) {
      if (*(byte *)(param_1 + 0xea) <= uVar2) {
        memw();
        return uVar1 & 0xffff;
      }
      iVar4 = param_1 + uVar2;
      if ((uVar1 & 0xffff) == 0x80) break;
      iVar3 = param_2 + uVar1;
      uVar2 = uVar2 + 1;
      uVar1 = uVar1 + 1;
      *(undefined1 *)(iVar3 + 0xf0) = *(undefined1 *)(iVar4 + 0xe4);
      memw();
      memw();
    }
  } while( true );
}

