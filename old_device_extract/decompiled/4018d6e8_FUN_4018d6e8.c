// Function : FUN_4018d6e8
// Address  : 0x4018d6e8
// Size     : 385 bytes


undefined4 FUN_4018d6e8(int param_1,char *param_2,int param_3,int param_4,undefined1 param_5)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 *puVar5;
  int *piVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  char *pcVar9;
  int *piVar10;
  int *piVar11;
  
  if (param_1 != 0) goto LAB_4018d708;
  uVar8 = 0x306;
  pcVar9 = "failed\n";
  while( true ) {
    memw();
    (*(code *)&SUB_40094c54)("p_event/esp_event.c",uVar8,"post_to",pcVar9);
LAB_4018d708:
    if (param_4 != 0) break;
    pcVar9 = "failed\n";
    uVar8 = 0x307;
  }
  if ((param_2 == (char *)0x0) && (param_3 != -1)) {
    uVar8 = (*(code *)&SUB_40094b80)();
    FUN_4012113c(1,"unknown event","ler_ctx",uVar8,"unknown event");
    uVar8 = 0xffffffff;
  }
  else {
    if (param_2 == (char *)0x0) {
      param_2 = "failed\n";
    }
    (*(code *)&SUB_4009019c)(*(undefined4 *)(param_1 + 0x10),0xffffffff);
    piVar4 = *(int **)(param_1 + 0x14);
LAB_4018d754:
    piVar2 = piVar4;
    if (piVar2 == (int *)0x0) goto LAB_4018d838;
    piVar4 = (int *)piVar2[2];
    if ((param_3 == -1) && (param_2 == "failed\n")) {
      memw();
      iVar1 = FUN_4018d1e0(piVar2,param_4,param_5);
      if (iVar1 != 0) goto LAB_4018d754;
    }
    else {
      puVar5 = (undefined4 *)piVar2[1];
LAB_4018d790:
      do {
        puVar3 = puVar5;
        if (puVar3 == (undefined4 *)0x0) goto LAB_4018d754;
        puVar5 = (undefined4 *)puVar3[3];
      } while (param_2 != (char *)*puVar3);
      if (param_3 == -1) {
        memw();
        iVar1 = FUN_4018d1e0(puVar3 + 1,param_4,param_5);
        if (iVar1 != 0) goto LAB_4018d790;
      }
      else {
        piVar11 = (int *)puVar3[2];
        do {
          do {
            piVar10 = piVar11;
            if (piVar10 == (int *)0x0) goto LAB_4018d790;
            piVar11 = (int *)piVar10[2];
          } while (param_3 != *piVar10);
          memw();
          iVar1 = FUN_4018d1e0(piVar10 + 1,param_4,param_5);
        } while ((iVar1 != 0) || (piVar10[1] != 0));
        piVar11 = (int *)puVar3[2];
        if (piVar10 == (int *)puVar3[2]) {
          puVar3[2] = piVar10[2];
        }
        else {
          do {
            piVar6 = piVar11;
            piVar11 = (int *)piVar6[2];
          } while (piVar10 != piVar11);
          piVar6[2] = piVar10[2];
          memw();
        }
        memw();
        (*(code *)&SUB_40094d80)(piVar10);
      }
      if ((puVar3[1] != 0) || (puVar3[2] != 0)) goto LAB_4018d790;
      puVar5 = (undefined4 *)piVar2[1];
      if (puVar3 == (undefined4 *)piVar2[1]) {
        piVar2[1] = puVar3[3];
      }
      else {
        do {
          puVar7 = puVar5;
          puVar5 = (undefined4 *)puVar7[3];
        } while (puVar3 != puVar5);
        puVar7[3] = puVar3[3];
        memw();
      }
      memw();
      (*(code *)&SUB_40094d80)(puVar3);
    }
    if ((piVar2[1] != 0) || (*piVar2 != 0)) goto LAB_4018d754;
    piVar4 = *(int **)(param_1 + 0x14);
    if (piVar2 == *(int **)(param_1 + 0x14)) {
      *(int *)(param_1 + 0x14) = piVar2[2];
    }
    else {
      do {
        piVar11 = piVar4;
        piVar4 = (int *)piVar11[2];
      } while (piVar2 != piVar4);
      piVar11[2] = piVar2[2];
      memw();
    }
    memw();
    (*(code *)&SUB_40094d80)(piVar2);
LAB_4018d838:
    uVar8 = 0;
    (*(code *)&SUB_4008fc8c)(*(undefined4 *)(param_1 + 0x10));
  }
  return uVar8;
}

