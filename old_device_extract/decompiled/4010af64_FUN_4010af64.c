// Function : FUN_4010af64
// Address  : 0x4010af64
// Size     : 40 bytes


undefined1 FUN_4010af64(int param_1,undefined4 param_2)

{
  undefined1 uVar1;
  
  uVar1 = 0xfa;
  if (param_1 != 0) {
    if (**(byte **)(param_1 + 4) >> 4 == 6) {
      uVar1 = FUN_40117650();
    }
    else {
      uVar1 = FUN_401167d8(param_1,param_2);
    }
  }
  return uVar1;
}

