// Function : FUN_4012cb68
// Address  : 0x4012cb68
// Size     : 329 bytes


undefined4 FUN_4012cb68(int *param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (param_1[0x15] != 0) {
    FUN_40129d74();
  }
  if (param_1[0x10] != 0) {
    FUN_4012cacc();
  }
  if (param_1[0x11] != 0) {
    FUN_4012ca14(param_1);
  }
  if (param_1[0x15] == 0) {
    iVar2 = FUN_4013ae30(1,0xd4);
    param_1[0x15] = iVar2;
  }
  if (param_1[0x10] == 0) {
    memw();
    iVar2 = FUN_4013ae30(1,0x80);
    param_1[0x10] = iVar2;
  }
  if (param_1[0x11] == 0) {
    memw();
    iVar2 = FUN_4013ae30(1,0x8d8);
    param_1[0x11] = iVar2;
  }
  if (((param_1[0x11] == 0) || (param_1[0x15] == 0)) || (param_1[0x10] == 0)) {
    memw();
    FUN_4013ae44();
    FUN_4013ae44(param_1[0x15]);
    FUN_4013ae44(param_1[0x10]);
    param_1[0x11] = 0;
    param_1[0x15] = 0;
    param_1[0x10] = 0;
    uVar3 = 0xffff8100;
  }
  else {
    FUN_4012c768(param_1[0x10]);
    FUN_4012c73c(param_1[0x15]);
    iVar2 = param_1[0x11];
    (*(code *)&SUB_4008b530)(iVar2,0,0x8d8);
    FUN_401416d8(iVar2 + 0x26c);
    FUN_4013ec3c(iVar2 + 0x2c4);
    FUN_401416c8(iVar2 + 0x26c);
    FUN_4013eca8(iVar2 + 0x2c4);
    FUN_4013f784(iVar2 + 0x324);
    FUN_4013f7ec(iVar2 + 0x324,0);
    FUN_4014098c(iVar2 + 0x398);
    FUN_40140a08(iVar2 + 0x398,1);
    *(undefined4 *)(iVar2 + 0x18) = 0x4012bd24;
    *(undefined4 *)(iVar2 + 8) = 0;
    *(undefined4 *)(iVar2 + 0xc) = 0;
    memw();
    FUN_401340ec(iVar2 + 0x28);
    uVar3 = 0;
    FUN_40134520(iVar2 + 0xa4);
    *(undefined1 *)(iVar2 + 4) = 3;
    memw();
    iVar2 = *param_1;
    if (*(char *)(iVar2 + 5) == '\x01') {
      iVar4 = param_1[0x11];
      *(int *)(iVar4 + 0x25c) = param_1[0x13];
      uVar1 = 0;
      if (*(char *)(iVar2 + 4) != '\0') {
        uVar1 = 2;
      }
      *(undefined1 *)(iVar4 + 7) = uVar1;
      memw();
      memw();
      FUN_40185804(param_1,0);
      uVar3 = 0;
    }
  }
  memw();
  return uVar3;
}

