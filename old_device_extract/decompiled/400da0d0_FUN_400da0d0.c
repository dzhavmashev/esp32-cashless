// Function : FUN_400da0d0
// Address  : 0x400da0d0
// Size     : 144 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400da0d0(int param_1)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  undefined1 auStack_34 [16];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  FUN_400f0780(0x3ffc5490," failed");
  FUN_400d98c0(auStack_34,*(undefined4 *)(param_1 + 8));
  iVar1 = (*(code *)&LAB_40183a7b_1)(auStack_34);
  iVar2 = 0x3ffc5490;
  if (iVar1 != 0) goto LAB_400da12e;
  pcVar3 = "ellular";
  do {
    FUN_400f0d70(param_1 + 0x20,pcVar3);
    param_1 = 0;
    while( true ) {
      FUN_400f0a50(auStack_34);
      iVar2 = iStack_24;
      memw();
      memw();
      if (iStack_24 == _DAT_3ffc5708) {
        return;
      }
      func_0x40082ecc();
LAB_400da12e:
      iVar1 = FUN_400d9e2c(*(undefined4 *)(param_1 + 4),auStack_34);
      if (iVar1 == 0) break;
      *(undefined4 *)(param_1 + 0x18) = 2;
      *(undefined1 *)(param_1 + 0x1c) = 1;
      *(undefined4 *)(param_1 + 0x30) = 0xffffffba;
      FUN_400f0780(iVar2,"figured");
      param_1 = iVar1;
    }
    pcVar3 = "ssfully";
  } while( true );
}

