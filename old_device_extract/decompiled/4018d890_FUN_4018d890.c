// Function : FUN_4018d890
// Address  : 0x4018d890
// Size     : 261 bytes


undefined4
FUN_4018d890(int param_1,int param_2,int param_3,int param_4,int param_5,undefined4 param_6)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined2 auStack_30 [2];
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  
  if (param_1 == 0) {
    (*(code *)&SUB_40094c54)("p_event/esp_event.c",0x33c,"ported\n","failed\n");
  }
  if ((param_2 == 0) || (param_3 == -1)) {
    return 0x102;
  }
  memw();
  (*(code *)&SUB_4008b530)(auStack_30,0);
  if ((param_4 != 0) && (param_5 != 0)) {
    iVar1 = (*(code *)&SUB_40094dd8)(1,param_5);
    if (iVar1 == 0) {
      return 0x101;
    }
    iStack_24 = (*(code *)&SUB_4008b3d0)(iVar1,param_4,param_5);
    auStack_30[0] = 0x101;
    memw();
  }
  iVar1 = *(int *)(param_1 + 8);
  iStack_2c = param_2;
  iStack_28 = param_3;
  if (iVar1 == 0) {
    memw();
    iVar1 = (*(code *)&SUB_4009019c)(*(undefined4 *)(param_1 + 0x10),param_6);
    if (iVar1 != 1) goto LAB_4018d92c;
    iVar2 = *(int *)(param_1 + 0xc);
    iVar1 = (*(code *)&SUB_40091388)();
    if (iVar2 != iVar1) {
      (*(code *)&SUB_4008fc8c)(*(undefined4 *)(param_1 + 0x10));
      goto LAB_4018d95a;
    }
    (*(code *)&SUB_4008fc8c)(*(undefined4 *)(param_1 + 0x10));
    uVar3 = 0;
  }
  else {
    iVar2 = (*(code *)&SUB_40091388)();
    uVar3 = 0;
    if (iVar1 != iVar2) {
LAB_4018d95a:
      uVar3 = param_6;
    }
  }
  iVar1 = (*(code *)&SUB_4008fab8)(*(undefined4 *)(param_1 + 4),auStack_30,uVar3,0);
  if (iVar1 == 1) {
    return 0;
  }
LAB_4018d92c:
  if (((char)auStack_30[0] != '\0') && (iStack_24 != 0)) {
    (*(code *)&SUB_40094d80)();
  }
  return 0x107;
}

