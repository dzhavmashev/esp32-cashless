// Function : FUN_4018549c
// Address  : 0x4018549c
// Size     : 60 bytes


byte FUN_4018549c(uint param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = 1;
  if ((param_1 - 1 < 0xfffffffe) &&
     (bVar1 = *(byte *)(param_2 + 0xeb) & 2, (*(byte *)(param_2 + 0xeb) & 2) != 0)) {
    bVar1 = 0;
    if ((*(uint *)(param_2 + 4) != param_1) &&
       (((*(uint *)(param_2 + 4) ^ param_1) & *(uint *)(param_2 + 0x1c)) == 0)) {
      uVar2 = *(uint *)(param_2 + 0x1c) ^ 0xffffffff;
      bVar1 = (uVar2 & param_1) == uVar2;
    }
  }
  return bVar1;
}

