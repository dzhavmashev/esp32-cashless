// Function : FUN_40116384
// Address  : 0x40116384
// Size     : 61 bytes


undefined4 FUN_40116384(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_40116310(param_1,&DAT_3ffc6480);
  uVar2 = 0xff;
  if (iVar1 != 0) {
    *(undefined1 *)(iVar1 + 9) = 2;
    uVar2 = 0;
    *(char *)(iVar1 + 0xc) = *(char *)(iVar1 + 0xc) + '\x01';
    memw();
    if (*(code **)(param_1 + 0xf4) != (code *)0x0) {
      memw();
      (**(code **)(param_1 + 0xf4))(param_1,&DAT_3ffc6480,1);
      uVar2 = 0;
    }
  }
  return uVar2;
}

