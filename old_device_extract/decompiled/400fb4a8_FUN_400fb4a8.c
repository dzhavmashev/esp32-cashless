// Function : FUN_400fb4a8
// Address  : 0x400fb4a8
// Size     : 32 bytes


undefined4 FUN_400fb4a8(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0x110b;
  if ((*(uint *)(param_1 + 0xc) & 0xfffffffd) == 0xfffffffc) {
    uVar1 = FUN_40184b28(param_1,0xfffffff8);
  }
  return uVar1;
}

