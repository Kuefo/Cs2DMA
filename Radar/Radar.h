#pragma once
#define _USE_MATH_DEFINES
#include "../Game.h"
#include "../OS-ImGui/OS-ImGui.h"
#include <math.h>
#include <tuple>


class Base_Radar
{
public:
	// �����״�����
	void SetSize(const float& Size);
	void SetPos(const Vec2& Pos);
	void SetRange(const float& Range);
	void SetCrossColor(const ImColor& Color);
	void SetProportion(const float& Proportion);
	void SetDrawList(ImDrawList* DrawList);


	std::pair<int, int> rotate_point(const std::pair<int, int>& center, const std::pair<int, int>& point, double angle);
	std::pair<int, int> world_to_minimap2(double x, double y, double pos_x, double pos_y, double scale, int map_w, int map_h);

	// ��ȡ�״�����
	float GetSize();
	Vec2 GetPos();
	// ��ӻ��Ƶ�
	void AddPoint(const Vec3& LocalPos, const float& LocalYaw, const Vec3& Pos, ImColor Color, float Yaw = 0.0f, int same_team = 1, float hp = 100, int is_bomb = 0);
	// ��Ⱦ
	void Save();

	void UpdateMap(std::string mapname);
public:
	ImDrawList* DrawList = nullptr;
	// ʮ����ʾ
	bool ShowCrossLine = true;
	// ʮ����ɫ
	ImColor CrossColor = ImColor(255, 255, 255, 255);
	// ����
	float Proportion = 2680;
	// Բ��뾶
	float CircleSize = 4;
	// ��ͷ�ߴ�
	float ArrowSize = 11;
	// Բ����ͷ�ߴ�
	float ArcArrowSize = 7;
	// �״ﷶΧ
	float RenderRange = 250;
	// ����Yaw����
	float LocalYaw = 0.0f;
	// ״̬
	bool Opened = true;
	// �״�������� 0:Բ�� 1:��ͷ 2:Բ����ͷ
	int  PointType = 0;

	void Render();

private:

	Vec2  Pos{ 0,0 };

	float Width = 200;

	std::vector<std::pair<Vec2, std::vector<std::pair<int, float>>>> Points_new;

};