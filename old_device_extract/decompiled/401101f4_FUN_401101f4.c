// Function : FUN_401101f4
// Address  : 0x401101f4
// Size     : 46 bytes


undefined4 FUN_401101f4(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  if ((param_1 == 0) || (*(char *)(param_1 + 0x30) == '\0')) {
    if ((param_3 == 0) || (*(char *)(param_3 + 0x14) != '\x06')) {
      uVar1 = FUN_401167b0(param_2);
    }
    else {
      uVar1 = FUN_401172d4();
    }
  }
  else {
    uVar1 = FUN_4010b938(*(char *)(param_1 + 0x30));
  }
  return uVar1;
}

