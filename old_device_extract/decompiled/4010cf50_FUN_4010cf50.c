// Function : FUN_4010cf50
// Address  : 0x4010cf50
// Size     : 44 bytes


undefined4 FUN_4010cf50(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = param_1;
  if (param_1 == 0) {
    iVar1 = (*(code *)&SUB_40094c54)(" LISTEN",0x90b,"s_netif","or poll");
  }
  uVar2 = FUN_4011ab64(iVar1,*(undefined2 *)(param_1 + 0x42),param_1 + 0x18,
                       *(undefined2 *)(param_1 + 0x44));
  return uVar2;
}

