// Function : FUN_40114568
// Address  : 0x40114568
// Size     : 120 bytes


void FUN_40114568(int param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined1 uVar6;
  uint in_t0;
  undefined8 uVar7;
  
  iVar3 = *(int *)(param_3 + 0xdc);
  if ((iVar3 != 0) && (uVar1 = (*(code *)&SUB_4008c01c)(iVar3), uVar1 != 0)) {
    uVar2 = uVar1;
    if (uVar1 <= 0x7dU - param_1) goto LAB_40114599;
    uVar5 = 0x722;
    while( true ) {
      uVar2 = (*(code *)&SUB_40094c54)("ONS_LEN",uVar5,"on_long","hcp_msg");
LAB_40114599:
      if (uVar2 < 0x100) break;
      uVar5 = 0x724;
    }
    uVar5 = FUN_401142d4(param_1,param_2,0xc,uVar2);
    uVar2 = 0;
    uVar7 = CONCAT44(0x7f,uVar5);
    while( true ) {
      uVar4 = (int)uVar7 + uVar2;
      if (uVar1 == uVar2) break;
      uVar6 = *(undefined1 *)(iVar3 + uVar2);
      if ((uint)((ulonglong)uVar7 >> 0x20) < (uVar4 & 0xffff)) {
        uVar2 = in_t0;
        uVar7 = FUN_40114310();
        uVar4 = uVar2;
        in_t0 = uVar2;
      }
      *(undefined1 *)(param_2 + uVar4) = uVar6;
      memw();
      uVar2 = uVar2 + 1;
      memw();
    }
  }
  return;
}

