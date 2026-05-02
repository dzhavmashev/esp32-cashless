// Function : FUN_4017173c
// Address  : 0x4017173c
// Size     : 78 bytes


int FUN_4017173c(undefined4 param_1,int param_2,int param_3)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int iVar3;
  uint local_30;
  uint auStack_2c [11];
  
  uVar1 = FUN_40171728(param_2);
  uVar2 = FUN_401713c4(uVar1,param_1);
  FUN_40171410(uVar1,uVar2,param_2 + 8,auStack_2c);
  uVar1 = FUN_40171728(param_3);
  uVar2 = FUN_401713c4(uVar1,param_1);
  FUN_40171410(uVar1,uVar2,param_3 + 8,&local_30);
  iVar3 = 1;
  if (auStack_2c[0] <= local_30) {
    iVar3 = -(uint)(auStack_2c[0] < local_30);
  }
  return iVar3;
}

